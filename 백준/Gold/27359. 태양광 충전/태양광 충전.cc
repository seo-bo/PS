#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, b = 0, c = 0;
		cin >> n >> b >> c;
		vector<ll>p(n + 1), f(n + 1), d(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> p[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			cin >> f[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			cin >> d[i];
		}
		vector<ll>dp(c + 1, LLONG_MAX);
		dp[b] = 0;
		for (int i = 1; i <= n; ++i)
		{
			vector<ll>temp(c + 1, LLONG_MAX);
			for (int j = c; j >= 0; --j)
			{
				if (dp[j] == LLONG_MAX)
				{
					continue;
				}
				ll pi = min(j + p[i], c);
				temp[pi] = min(temp[pi], dp[j] + f[i] * d[i]);
				if (j - d[i] >= 0)
				{
					temp[j - d[i]] = min(temp[j - d[i]], dp[j]);
				}
			}
			dp = move(temp);
		}
		ll ans = LLONG_MAX;
		for (int i = b; i <= c; ++i)
		{
			ans = min(ans, dp[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}