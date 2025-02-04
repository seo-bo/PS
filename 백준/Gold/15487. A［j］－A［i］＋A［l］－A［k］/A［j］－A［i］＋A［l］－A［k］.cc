#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(5, -1e9));
	function<ll(int, int)> dfs = [&](int idx, int depth)
		{
			if (depth == 4)
			{
				return 0LL;
			}
			if (idx > n)
			{
				return 1LL * INT_MIN;
			}
			if (dp[idx][depth] != -1e9)
			{
				return dp[idx][depth];
			}
			ll res = dfs(idx + 1, depth);
			if (depth == 1 || depth == 3)
			{
				res = max(res, dfs(idx + 1, depth + 1) + v[idx]);
			}
			if (depth == 0 || depth == 2)
			{
				res = max(res, dfs(idx + 1, depth + 1) - v[idx]);
			}
			return dp[idx][depth] = res;
		};
	cout << dfs(1, 0);
	return 0;
}