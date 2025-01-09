#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>>dir = { {1,0},{0,1},{1,1} };
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>grid(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	dp[1][1] = grid[1][1];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (nx > 0 && ny > 0 && nx <= n && ny <= m)
				{
					if (dp[i][j] + grid[nx][ny] > dp[nx][ny])
					{
						dp[nx][ny] = dp[i][j] + grid[nx][ny];
					}
				}
			}
		}
	}
	cout << dp[n][m];
	return 0;
}