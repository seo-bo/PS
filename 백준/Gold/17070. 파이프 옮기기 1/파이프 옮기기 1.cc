#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3, 0)));
	dp[1][2][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 2; j <= n; ++j)
		{
			if (v[i][j])
			{
				continue;
			}
			dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			if (!v[i-1][j] && !v[i][j-1] && !v[i-1][j-1])
			{
				dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; ++i)
	{
		ans += dp[n][n][i];
	}
	cout << ans;
	return 0;
}