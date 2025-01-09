#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>dp(n + 5, 0);
	dp[1] = 1, dp[2] = 1;
	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[n];
	return 0;
}