#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, k = 0, c = 0;
	cin >> x >> k >> c;
	vector<vector<ll>>dp(k + 1, vector<ll>(x + 1, LLONG_MAX));
	for (int i = 0; i <= k; ++i)
	{
		dp[i][0] = 0;
		if (i == 0)
		{
			for (int j = 1; j <= x; ++j)
			{
				dp[i][j] = j + c;
			}
		}
	}
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= x; ++j)
		{
			ll left = 1, right = j, res = j;
			while (left <= right)
			{
				ll mid = (left + right) / 2;
				if (j - mid >= 0)
				{
					if (dp[i][j - mid] <= dp[i - 1][j])
					{
						right = mid - 1;
						res = mid;
					}
					else
					{
						left = mid + 1;
					}
				}
				else
				{
					left = mid + 1;
				}
			}
			dp[i][j] = res + c + dp[i - 1][j];
		}
	}
	cout << dp[k][x];
	return 0;
}
