#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>tx(m + 1), tc(m + 1);
	for (ll i = 1; i <= m; ++i)
	{
		cin >> tx[i] >> tc[i];
	}
	vector<ll>per(m + 1);
	iota(per.begin(), per.end(), 0);
	sort(per.begin() + 1, per.end(), [&](const ll& a, const ll& b)
		{
			return tx[a] < tx[b];
		});
	vector<ll>x(m + 1), c(m + 1);
	vector<vector<ll>>v(m + 1);
	for (ll i = 1; i <= m; ++i)
	{
		x[i] = tx[per[i]];
		c[i] = tc[per[i]];
	}
	for (ll i = 1; i <= m; ++i)
	{
		for (ll j = i + 1; j <= m; ++j)
		{
			if (x[j] % x[i] == 0)
			{
				v[i].push_back(j);
			}
		}
	}
	vector<vector<ll>>dp(m + 1, vector<ll>(n + 1, LLONG_MIN));
	vector<vector<ll>>p(m + 1, vector<ll>(n + 1, LLONG_MIN));
	for (ll i = 1; i <= m; ++i)
	{
		dp[i][0] = 0;
	}
	for (ll i = m; i >= 1; --i)
	{
		for (ll j = 0; j <= n; ++j)
		{
			if (v[i].empty())
			{
				if (j == 0)
				{
					p[i][j] = 0;
				}
			}
			else
			{
				for (auto& k : v[i])
				{
					p[i][j] = max(p[i][j], dp[k][j]);
				}
			}
		}
		for (ll j = 1; j <= n; ++j)
		{
			ll pivot = LLONG_MIN;
			for (ll k = 1; k <= j && k <= c[i]; ++k)
			{
				if (p[i][j - k] == LLONG_MIN)
				{
					continue;
				}
				dp[i][j] = max(dp[i][j], p[i][j - k] + x[i] * k);
			}
		}
	}
	ll ans = LLONG_MIN;
	for (int i = 1; i <= m; ++i)
	{
		ans = max(ans, dp[i][n]);
	}
	cout << ((ans < 0) ? -1 : ans);
	return 0;
}