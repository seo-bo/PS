#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(4, -1)));
	function<int(int, int, int)> dfs = [&](int x, int y, int d)
		{
			if (x == n && y >= 0 && y < m)
			{
				return 0;
			}
			if (!(x >= 0 && x < n && y >= 0 && y < m))
			{
				return (int)1e5;
			}
			if (dp[x][y][d] != -1)
			{
				return dp[x][y][d];
			}
			int res = 1e5;
			if (d != 1)
			{
				res = min(res, dfs(x + 1, y - 1, 1) + v[x][y]);
			}
			if (d != 2)
			{
				res = min(res, dfs(x + 1, y, 2) + v[x][y]);
			}
			if (d != 3)
			{
				res = min(res, dfs(x + 1, y + 1, 3) + v[x][y]);
			}
			return dp[x][y][d] = res;
		};
	int ans = INT_MAX;
	for (int i = 0; i < m; ++i)
	{
		ans = min(ans, dfs(0, i, 0));
	}
	cout << ans;
	return 0;
}