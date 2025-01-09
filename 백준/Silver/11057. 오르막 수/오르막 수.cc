#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>dp(1002, vector<int>(11, 0));
	for (int i = 0; i <= 9; ++i)
	{
		dp[1][i] = 1;
		dp[1][10]++;
	}
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
			dp[i][10] = (dp[i][10] + dp[i][j]) % MOD;
		}
	}
	cout << dp[n][10];
	return 0;
}