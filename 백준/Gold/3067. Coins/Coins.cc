#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		int k = 0;
		cin >> k;
		vector<int>dp(k + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = v[i]; j <= k; ++j)
			{
				dp[j] += dp[j - v[i]];
			}
		}
		cout << dp[k] << '\n';
	}
	return 0;
}