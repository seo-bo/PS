#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>dp(n + 5, 1e9);
	dp[2] = dp[5] = 1, dp[4] = 2;
	for (int i = 6; i <= n; ++i)
	{
		dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
	}
	dp[n] == 1e9 ? cout << -1 : cout << dp[n];
	return 0;
}