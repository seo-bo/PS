#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int>dp(1000002);
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= 1000000; ++i)
	{
		dp[i] = ((ll)dp[i - 1] + (ll)dp[i - 2] + (ll)dp[i - 3]) % MOD;
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}