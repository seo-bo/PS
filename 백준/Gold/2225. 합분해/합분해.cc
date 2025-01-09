#include <bits/stdc++.h>
#define MOD 1000000000
typedef long long ll;
typedef long double lb;
using namespace std;

ll dp[201][201] = { 0, }; // 갯수, 합

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	for (int i = 0; i <= n; ++i)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= k; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			for (int z = 0; z <= j; ++z)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][z]) % MOD;
			}
		}
	}
	cout << dp[k][n];
	return 0;
}