#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<ll>>dp(n + 1, vector<ll>(3, 0));
	dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 2; ++j)
		{
			for (int k = 0; k <= 2; ++k)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][(j - k + 3) % 3]) % MOD;
			}
		}
	}
	cout << dp[n][0];
	return 0;
}