#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1), cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		v.push_back(v[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	vector<vector<ll>>dp(2 * n + 2, vector<ll>(2 * n + 2, -1));
	function<ll(int, int)> dfs = [&](int left, int right)
		{
			if (left == right)
			{
				return cost[v[left]] + 1;
			}
			if (dp[left][right] != -1)
			{
				return dp[left][right];
			}
			ll res = LLONG_MAX / 8;
			res = min(res, dfs(left, right - 1) + cost[v[right]] + 1);
			for (int i = left; i < right; ++i)
			{
				if (v[right] == v[i])
				{
					ll temp = dfs(left, i);
					if (i + 1 <= right - 1)
					{
						temp += dfs(i + 1, right - 1);
					}
					res = min(res, temp + right - i);
				}
			}
			return dp[left][right] = res;
		};
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		ans = min(ans, dfs(i, i + n - 1));
	}
	cout << ans;
	return 0;
}
