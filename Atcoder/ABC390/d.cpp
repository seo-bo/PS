#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n), sum(1 << n);
	vector<vector<ll>>dp(1 << n);
	vector<bool>visited(1 << n, false);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 0; i < (1 << n); ++i)
	{
		ll temp = __builtin_ctz(i);
		sum[i] = sum[i ^ (1 << temp)] + v[temp];
	}
	function<vector<ll>(int)> dfs = [&](int mask)
		{
			if (mask == 0)
			{
				return vector<ll>{ 0 };
			}
			if (visited[mask])
			{
				return dp[mask];
			}
			visited[mask] = true;
			ll tt = __builtin_ctz(mask);
			ll p = mask ^ (1 << tt);
			for (ll i = mask ^ (1 << tt);; i = (i - 1) & p)
			{
				ll a = mask ^ (i | (1 << tt)), b = sum[i | (1 << tt)];
				vector<ll>sz = dfs(a);
				for (auto& j : sz)
				{
					dp[mask].push_back(j ^ b);
				}
				if (!i)
				{
					break;
				}
			}
			sort(dp[mask].begin(), dp[mask].end());
			dp[mask].erase(unique(dp[mask].begin(), dp[mask].end()), dp[mask].end());
			return dp[mask];
		};
	cout << (dfs((1 << n) - 1)).size();
	return 0;
}
