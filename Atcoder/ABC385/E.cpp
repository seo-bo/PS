#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<vector<ll>>graph(n + 1);
	vector<ll>degree(n + 1, 0);
	for (ll i = 0; i < n - 1; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; ++i)
	{
		if (!degree[i])
		{
			continue;
		}
		vector<ll>temp;
		for (auto& j : graph[i])
		{
			temp.push_back(degree[j] - 1);
		}
		sort(temp.rbegin(), temp.rend());
		ll res = 0;
		for (ll j = 0; j < temp.size(); ++j)
		{
			if (temp[j] < 1)
			{
				break;
			}
			ll pivot = j + 1;
			res = max(res, 1 + pivot * (1LL + temp[j]));
		}
		ans = max(res, ans);
	}
	cout << n - ans;
	return 0;
}
