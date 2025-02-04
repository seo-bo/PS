#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	vector<vector<int>>dp(452, vector<int>(50003, 0));
	dp[1][0] = dp[1][1] = 1;
	for (int i = 1; i <= 450; ++i)
	{
		for (int j = 0; j <= 50000; ++j)
		{
			int tot = i * (i + 1) / 2;
			if (j > tot)
			{
				break;
			}
			int other = tot - j;
			if (j + i + 1 <= 50000)
			{
				dp[i + 1][j + i + 1] = (dp[i + 1][j + i + 1] + dp[i][j]) % MOD;
			}
			if (other + i + 1 <= 50000)
			{
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
			}
		}
	}
	for (int i = 1; i <= 450; ++i)
	{
		for (int j = 1; j <= 50000; ++j)
		{
			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
		}
	}
	while (T--)
	{
		int a = 0, b = 0, ans = 0, pivot = 0;
		cin >> a >> b;
		while ((pivot + 1) * (pivot + 2) / 2 <= a + b)
		{
			pivot++;
		}
		for (int i = 1; i <= pivot; ++i)
		{
			int total = i * (i + 1) / 2;
			int left = max(0, total - a), right = min(total, b);
			ans = (ans + dp[i][right]) % MOD;
			if (left != 0)
			{
				ans = (ans - dp[i][left - 1] + MOD) % MOD;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}