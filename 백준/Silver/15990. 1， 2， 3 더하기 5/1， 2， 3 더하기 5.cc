#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<ll>>dp(100002, vector<ll>(4));
	for (int i = 1; i <= 3; ++i)
	{
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 3; i <= 100000; ++i)
	{
		dp[i][1] = (dp[i][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i][2] + dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i][3] + dp[i - 3][1] + dp[i - 3][2]) % MOD;
		dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % MOD;
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		cout << dp[n][0] << '\n';
	}
	return 0;
}