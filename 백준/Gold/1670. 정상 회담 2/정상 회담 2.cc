#include <bits/stdc++.h>
#define MOD 987654321
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (n % 2)
	{
		cout << 0;
		return 0;
	}
	unordered_map<int, ll>dp;
	dp[0] = 1, dp[2] = 1;
	for (int i = 4; i <= n; i += 2)
	{
		ll ans = 0;
		for (int j = i - 2; j >= 0; j -= 2)
		{
			ans = (ans + ((dp[j] * dp[i - 2 - j]) % MOD)) % MOD;
		}
		dp[i] = ans;
	}
	cout << dp[n];
	return 0;
}