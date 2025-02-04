#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>siz(n, 0), cost(n, 0);
	vector<vector<pll>>v(n, vector<pll>(2));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> v[i][j].first >> v[i][j].second;
		}
		cin >> cost[i];
	}
	auto check = [&](vector<pll> s, vector<pll> e)
		{
			auto ccw = [&](pll a, pll b, pll c)
				{
					ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
					temp -= a.second * b.first + b.second * c.first + c.second * a.first;
					return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
				};
			ll xy = ccw(s[0], s[1], e[0]) * ccw(s[0], s[1], e[1]);
			ll yx = ccw(e[0], e[1], s[0]) * ccw(e[0], e[1], s[1]);
			if (!xy && !yx)
			{
				if (s[0] > s[1])
				{
					swap(s[0], s[1]);
				}
				if (e[0] > e[1])
				{
					swap(e[0], e[1]);
				}
				return (s[0] <= e[1] && s[1] >= e[0]);
			}
			return (xy <= 0 && yx <= 0);
		};
	vector<vector<ll>>degree(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (check(v[i], v[j]))
			{
				degree[i].push_back(j);
				degree[j].push_back(i);
				siz[i]++;
				siz[j]++;
			}
		}
	}
	auto cmp = [&](const ll& a, const ll& b)
		{
			return cost[a] > cost[b];
		};
	priority_queue<ll, vector<ll>, function<bool(ll, ll)>>pq(cmp);
	for (int i = 0; i < n; ++i)
	{
		pq.push(i);
	}
	ll ans = 0;
	while (!pq.empty())
	{
		ll cur = pq.top();
		pq.pop();
		ans += cost[cur] * (siz[cur] + 1);
		for (auto& i : degree[cur])
		{
			siz[i]--;
		}
	}
	cout << ans;
	return 0;
}