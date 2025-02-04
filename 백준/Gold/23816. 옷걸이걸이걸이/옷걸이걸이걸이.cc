#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[5001][10001] = { 0, };

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= 15 && dp[i - 1][j - 15] != -1)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 15]);
			}
			if (j >= 7 && dp[i - 1][j - 7] != -1)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 7] + 4);
			}
			if (j >= 3 && dp[i - 1][j - 3] != -1)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 3] + 2);
			}
			if (j >= 1 && dp[i - 1][j - 1] != -1)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}