#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<ll>>dp(n + 3, vector<ll>(2, 0));
	dp[1][0] = 2, dp[2][0] = 7, dp[2][1] = 1;
	for (int i = 3; i <= n; ++i)
	{
		dp[i][1] = (dp[i - 1][1] + dp[i - 3][0]) % MOD;
		dp[i][0] = (3LL * dp[i - 2][0] + 2LL * dp[i - 1][0] + 2 * dp[i][1]) % MOD;
	}
	cout << dp[n][0];
	return 0;
}