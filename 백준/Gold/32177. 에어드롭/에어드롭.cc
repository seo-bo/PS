#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, k = 0, t = 0, x = 0, y = 0, ver = 0;
	cin >> n >> k >> t >> x >> y >> ver;
	k = k * k;
	vector<ti>v(n);
	vector<bool>visited(n + 1, false);
	auto dis = [&](ll x1, ll y1, ll x2, ll y2)->ll
		{
			return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		};
	for (auto& [a, b, c, d] : v)
	{
		cin >> a >> b >> c >> d;
	}
	queue<ll>q;
	set<ll>ans;
	for (int i = 0; i < n; ++i)
	{
		auto [a, b, c, d] = v[i];
		ll dist = dis(x, y, a, b);
		if (dist <= k && abs(ver - c) <= t)
		{
			q.push(i);
			visited[i] = true;
			if (d)
			{
				ans.insert(i + 1);
			}
		}
	}
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		auto [a, b, c, d] = v[cur];
		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
			{
				auto [e, f, g, h] = v[i];
				ll dist = dis(a, b, e, f);
				if (dist <= k && abs(c - g) <= t)
				{
					q.push(i);
					visited[i] = true;
					if (h)
					{
						ans.insert(i + 1);
					}
				}
			}
		}
	}
	if (ans.empty())
	{
		cout << 0;
	}
	else
	{
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
	}
	return 0;
}