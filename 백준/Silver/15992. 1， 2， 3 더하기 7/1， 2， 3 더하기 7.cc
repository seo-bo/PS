#include <bits/stdc++.h>
#include <unordered_map>
#define MOD 1000000009
using namespace std;
typedef long long ll;

ll dp[1001][1001] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[1][1] = 1; dp[2][1] = 1; dp[2][2] = 1; dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
	for (int i = 4; i <= 1000; ++i)
	{
		/***********
		4라면?
		2개로 만드는 거 2 + 2 / 1 + 3 / 3 +1
		3개로 만드는 거 1 + 1 + 2 / 1 + 2 + 1 / 2 + 1 + 1
		4개로 만드는 거 1 + 1 + 1 + 1
		*************/
		for (int j = 2; j <= i; ++j)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % MOD;
		}
	}
	int test = 0;
	cin >> test;
	while (test--)
	{
		int row =0, col = 0;
		cin >> row >> col;
		cout << dp[row][col] << "\n";
	}
	return 0;
}