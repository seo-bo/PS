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
	int n = 0;
	cin >> n;
	vector<vector<int>>grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];
		}
	}
	vector<vector<ll>>dp(n, vector<ll>(n, 0));
	dp[0][0] = 1;
	vector<vector<int>>direction = { {0,1},{1,0} };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (dp[i][j] && grid[i][j])
			{
				for (int k = 0; k < 2; ++k)
				{
					int nx = i + grid[i][j] * direction[k][0];
					int ny = j + grid[i][j] * direction[k][1];
					if (nx >= 0 && ny >= 0 && nx < n && ny < n)
					{
						dp[nx][ny] += dp[i][j];
					}
				}
			}
		}
	}
	cout << dp[n - 1][n - 1];
	return 0;
}