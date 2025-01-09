#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>>dp(1LL << n, vector<int>(n, -1));
	function<int(int, int)> dfs = [&](int mask, int node)
		{
			if (mask == (1 << n) - 1)
			{
				return 0;
			}
			if (dp[mask][node] != -1)
			{
				return dp[mask][node];
			}
			int cost = 1e8;
			for (int i = 0; i < n; ++i)
			{
				if (!(mask & (1 << i)))
				{
					cost = min(cost, dfs(mask | (1 << i), node + 1) + v[node][i]);
				}
			}
			return dp[mask][node] = cost;
		};
	cout << dfs(0, 0);
	return 0;
}