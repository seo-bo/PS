#include <bits/stdc++.h>
#include <unordered_map>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;

ll dp[1005][27] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, M = 0;
	cin >> N >> M;
	for (int i = 0; i < 26; ++i)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= M; ++i)
	{
		for (int k = 0; k < 26; ++k)
		{
			for (int z = 0; z < 26; ++z)
			{
				if (abs(k - z) >= N)
				{
					dp[i][k] = (dp[i - 1][z] + dp[i][k]) % MOD;
				}
			}
			dp[i][26] = (dp[i][k] + dp[i][26]) % MOD;
		}
	}
	cout << dp[M][26];
}