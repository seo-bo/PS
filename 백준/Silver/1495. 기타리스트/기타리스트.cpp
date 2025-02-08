#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, s = 0, m = 0;
	cin >> n >> s >> m;
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	dp[0][s] = s;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (dp[i - 1][j] != -1)
			{
				if (j + v[i] <= m)
				{
					dp[i][j + v[i]] = max(dp[i][j + v[i]], j + v[i]);
				}
				if (j - v[i] >= 0)
				{
					dp[i][j - v[i]] = max(dp[i][j - v[i]], j - v[i]);
				}
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; ++i)
	{
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}