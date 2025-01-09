#include <bits/stdc++.h>
#define MOD 1000000;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<vector<ll>>>dp(n + 2, vector<vector<ll>>(2, vector<ll>(3, 0)));
	dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
		dp[i][0][1] = dp[i - 1][0][0];
		dp[i][1][1] = dp[i - 1][1][0];
		dp[i][0][2] = dp[i - 1][0][1];
		dp[i][1][2] = dp[i - 1][1][1];
	}
	ll ans = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			ans = (ans + dp[n][i][j]) % MOD;
		}
	}
	cout << ans;
	return 0;
}