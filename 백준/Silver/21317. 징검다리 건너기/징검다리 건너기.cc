#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0, ans = INT_MAX;
	cin >> n;
	vector<vector<int>>dp(21, vector<int>(2, 1e7));
	vector<pii>v(n + 1);
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	cin >> k;
	dp[1][0] = 0;
	for (int i = 1; i <= n - 1; ++i)
	{
		if (i + 1 <= n)
		{
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + v[i].first);
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + v[i].first);
		}
		if (i + 2 <= n)
		{
			dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + v[i].second);
			dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + v[i].second);
		}
		if (i + 3 <= n)
		{
			dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + k);
		}
	}
	cout << min(dp[n][0], dp[n][1]);
	return 0;
}