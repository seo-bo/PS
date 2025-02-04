#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>dp(51, 0);
	dp[0] = dp[1] = 1;
	int n = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = (dp[i - 2] + dp[i - 1] + 1LL) % MOD;
	}
	cout << dp[n];
	return 0;
}