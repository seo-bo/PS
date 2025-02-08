#include <bits/stdc++.h>
#include <unordered_map>
#define MOD 987654321
using namespace std;
typedef long long ll;
typedef long double lb;

ll dp[100001][10];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	ll result = 0;
	//1자리 숫자고, 1일때 2일 때.............
	dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = dp[1][7] = dp[1][8] = dp[1][9] = 1;
	for (int i = 2; i <= num; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			for (int k = max(1, j - 2); k <= min(9, j + 2); ++k)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
			if (i == num)
			{
				result = (result + dp[i][j]) % MOD;
			}
		}
	}
	if (num == 1)
	{
		cout << 9;
		return 0;
	}
	cout << result;
	return 0;
}