#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<ll>>dp(n + 1,vector<ll>(11));
	for (int i = 1; i <= 9; ++i)
	{
		dp[1][i] = 1;
		dp[1][10]++;
	}
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j != 0)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			}
			if (j != 9)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
			}
			dp[i][10] = (dp[i][10] + dp[i][j]) % MOD;
		}
	}
	cout << dp[n][10];
	return 0;
}