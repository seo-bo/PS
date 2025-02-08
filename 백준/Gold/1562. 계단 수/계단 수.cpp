#include <bits/stdc++.h>
#include <regex>
#define MOD 1000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (n < 10)
	{
		cout << 0;
		return 0;
	}
	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(10, vector<int>(1 << 10)));
	// 자리, 현재수, 방문처리
	for (int i = 1; i <= 9; ++i)
	{
		dp[1][i][1 << i] = 1;
	}
	for (int i = 2; i <= n; ++i) // 자리
	{
		for (int j = 0; j <= 9; ++j) // 현재수
		{
			for (int k = 0; k < (1 << 10); ++k)
			{
				if (j < 9)
				{
					dp[i][j][k | (1 << j)] = (dp[i - 1][j + 1][k] + dp[i][j][k | (1 << j)]) % MOD;
				}
				if (j > 0)
				{
					dp[i][j][k | (1 << j)] = (dp[i - 1][j - 1][k] + dp[i][j][k | (1 << j)]) % MOD;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= 9; ++i)
	{
		ans = (ans + dp[n][i][(1 << 10) - 1]) % MOD;
	}
	cout << ans;
	return 0;
}