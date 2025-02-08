#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>dp(n + 3, 0);
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j <= i - 3; ++j)
		{
			dp[i] = max(dp[i], dp[j] * (i - j - 1));
		}
	}
	cout << dp[n];
	return 0;
}
