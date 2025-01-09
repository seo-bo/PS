#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>prefix(n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	int k = 0;
	cin >> k;
	vector<vector<int>>dp(n + 2, vector<int>(4, 0));
	for (int i = k; i <= n; ++i)
	{
		dp[i][1] = max(dp[i - 1][1], prefix[i] - prefix[i - k]);
		dp[i][2] = max(dp[i - 1][2], dp[i - k][1] + prefix[i] - prefix[i - k]);
		dp[i][3] = max(dp[i - 1][3], dp[i - k][2] + prefix[i] - prefix[i - k]);
	}
	cout << dp[n][3];
	return 0;
}