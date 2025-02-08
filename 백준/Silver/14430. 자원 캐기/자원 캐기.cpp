#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

int grid[305][305] = { 0, };
int dp[305][305] = { 0, };
int n = 0, m = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] = max(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
		}
	}
	cout << dp[n][m];
	return 0;
}