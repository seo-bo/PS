#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m = 0, n = 0;
	cin >> m >> n;
	vector<vector<int>>v(m, vector<int>(n));
	vector<vector<int>>dp(m, vector<int>(n, -1));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	function<int(int, int)> dfs = [&](int x, int y) -> int
		{
			if (x == m - 1 && y == n - 1)
			{
				return 1;
			}
			if (dp[x][y] != -1)
			{
				return dp[x][y];
			}
			dp[x][y] = 0;
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && ny >= 0 && nx < m && ny < n && v[x][y] > v[nx][ny])
				{
					dp[x][y] += dfs(nx, ny);
				}
			}
			return dp[x][y];
		};
	cout << dfs(0, 0);
	return 0;
}