#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>dp(200001, 0);
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 200000; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0;
		cin >> a;
		cout << dp[a] << '\n';
	}
	return 0;
}