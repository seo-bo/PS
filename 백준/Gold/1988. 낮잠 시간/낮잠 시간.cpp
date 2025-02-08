#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	int dp[n + 1][m + 1][2];
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				if (dp[i][j][k] == -1)
				{
					continue;
				}
				dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k]);
				if (j < m)
				{
					if (!k)
					{
						dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0]);
					}
					else
					{
						dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][1] + v[i + 1]);
					}
				}
			}
		}
	}
	cout << max(dp[n][m][0], dp[n][m][1]);
	return 0;
}