#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>cost(n + 1);
	ll ans = LLONG_MIN;
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		ans = max(ans, cost[i]);
	}
	int pivot = INT_MIN;
	vector<pii>v(1);
	function<void(int, int)> dfs = [&](int depth, int node)
		{
			if (node > n)
			{
				return;
			}
			dfs(depth + 1, node * 2);
			v.push_back(make_pair(depth, node));
			pivot = max(pivot, depth);
			dfs(depth + 1, node * 2 + 1);
		};
	dfs(1, 1);
	for (int i = 1; i <= pivot; ++i)
	{
		for (int j = i; j <= pivot; ++j)
		{
			int idx = -1;
			for (int k = 1; k <= n; ++k)
			{
				if (i <= v[k].first && v[k].first <= j)
				{
					idx = k;
					break;
				}
			}
			ll res = cost[v[idx].second], dp = cost[v[idx].second];
			for (int k = idx + 1; k <= n; ++k)
			{
				if (i <= v[k].first && v[k].first <= j)
				{
					dp = max(dp + cost[v[k].second], cost[v[k].second]);
					res = max(res, dp);
				}
			}
			ans = max(ans, res);
		}
	}
	cout << ans;
	return 0;
}