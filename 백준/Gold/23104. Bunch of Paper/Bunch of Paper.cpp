#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<ll>>dp(n + 2, vector<ll>(m + 2, 0));
	for (int i = 1; i <= m; ++i)
	{
		dp[n][i] = 1;
	}
	for (int i = n - 1; i >= 1; --i)
	{
		vector<ll>ok(m + 2, 0);
		for (int j = m; j >= 1; --j)
		{
			ok[j] = (ok[j + 1] + dp[i + 1][j]) % MOD;
		}
		for (int j = 1; j <= m; ++j)
		{
			auto it = lower_bound(v[i + 1].begin() + 1, v[i + 1].end(), v[i][j]) - v[i + 1].begin();
			if (it <= m)
			{
				dp[i][j] = ok[it];
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		ans = (ans + dp[1][i]) % MOD;
	}
	cout << ans;
	return 0;
}