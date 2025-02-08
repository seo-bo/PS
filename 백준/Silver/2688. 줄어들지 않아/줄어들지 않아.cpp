#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

ll dp[11][65] = { 0, };
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= 9; ++i)
	{
		dp[i][1] = 1;
		dp[10][1]++;
	}
	for (int i = 2; i <= 64; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				dp[j][i] += dp[k][i - 1];
			}
			dp[10][i] += dp[j][i];
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		cout << dp[10][n] << "\n";
	}
}