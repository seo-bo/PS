#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<pii>v(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, LLONG_MIN));
	dp[0][0] = 0;
	for (ll i = 1; i <= n; ++i)
	{
		auto [a, b] = v[i];
		for (ll j = 0; j <= m; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= b && dp[i - 1][j - b] != LLONG_MIN)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - b] + a);
			}
		}
	}
	ll ans = LLONG_MIN, idx = -1;
	for (ll i = 1; i <= m; ++i)
	{
		if (ans < dp[n][i])
		{
			ans = dp[n][i];
			idx = i;
		}
	}
	if (ans == LLONG_MIN)
	{
		cout << -1;
		return 0;
	}
	vector<int>res;
	for (int i = n; i >= 1; --i)
	{
		auto [a, b] = v[i];
		if (idx >= b && dp[i][idx] == dp[i - 1][idx - b] + a)
		{
			res.push_back(i);
			idx -= b;
		}
	}
	if (res.empty())
	{
		cout << -1;
		return 0;
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto& i : res)
	{
		cout << i << ' ';
	}
	return 0;
}