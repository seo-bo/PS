#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	map<char, int>mm = { {'U',0},{'R',1},{'D',2},{'L',3} };
	vector<vector<int>>dir = { {-1,0},{0,1},{1,0},{0,-1} };
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = mm[str[j]];
		}
	}
	vector<vector<int>>dp(n, vector<int>(m, -1));
	function<int(int, int)> dfs = [&](int x, int y)
		{
			if (x < 0 || x >= n || y < 0 || y >= m)
			{
				return 1;
			}
			if (dp[x][y] == 0 || dp[x][y] == 1)
			{
				return dp[x][y];
			}
			if (dp[x][y] == -2)
			{
				return 0;
			}
			dp[x][y] = -2;
			int p = v[x][y], nx = x + dir[p][0], ny = y + dir[p][1];
			return dp[x][y] = dfs(nx, ny);
		};
	dfs(0, 0);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (dfs(i, j) == 1)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}