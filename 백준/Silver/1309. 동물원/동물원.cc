#include <bits/stdc++.h>
#define MOD 9901
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>dp(n + 1, vector<int>(3, 0));
	dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
	}
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
	return 0;
}