#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 1;
	while (1)
	{
		int n = 0;
		cin >> n;
		if (!n)
		{
			return 0;
		}
		vector<vector<int>>v(n + 1, vector<int>(4, 0));
		vector<vector<int>>dp(n + 1, vector<int>(4, 1e8));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= 3; ++j)
			{
				cin >> v[i][j];
			}
		}
		dp[1][2] = v[1][2], dp[1][3] = dp[1][2] + v[1][3];
		for (int i = 2; i <= n; ++i)
		{
			dp[i][1] = min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]) + v[i][1]);
			dp[i][2] = min(dp[i][2], min(dp[i - 1][1], min(dp[i - 1][2], min(dp[i - 1][3], dp[i][1]))) + v[i][2]);
			dp[i][3] = min(dp[i][3], min(dp[i - 1][2], min(dp[i - 1][3], dp[i][2])) + v[i][3]);
		}
		cout << cnt++ << ". " << dp[n][2] << '\n';
	}
	return 0;
}