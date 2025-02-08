#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>p(11);
	for (ll i = 1; i <= m; ++i)
	{
		p[__builtin_popcount(i)].push_back(i);
	}
	vector<ll> v(n + 1);
	for (ll i = n; i >= 1; --i)
	{
		cin >> v[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 2, INT_MIN));
	ll cnt = INT_MIN, pv = 0;
	for (auto& j : p[v[1]])
	{
		dp[1][j] = 0;
	}
	for (ll i = 2; i <= n; ++i)
	{
		if (p[v[i]].empty())
		{
			cout << -1;
			return 0;
		}
		for (auto& j : p[v[i]])
		{
			ll pre = j - 1, nxt = j + 1;
			if (pre >= 1 && v[i - 1] == __builtin_popcount(pre))
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][pre] + 1);
			}
			if (nxt <= m && v[i - 1] == __builtin_popcount(nxt))
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][nxt] + 1);
			}
			dp[i][j] = max(dp[i][j], pv);
			cnt = max(dp[i][j], cnt);
		}
		if (cnt == INT_MIN)
		{
			cout << -1;
			return 0;
		}
		pv = cnt;
		cnt = INT_MIN;
	}
	if (pv == -1)
	{
		cout << -1;
		return 0;
	}
	vector<ll> ans;
	{
		ll idx = INT_MAX, id = pv;
		for (int i = 1; i <= m; ++i)
		{
			if (dp[n][i] == id)
			{
				idx = min(idx, (ll)i);
			}
		}
		if (idx == INT_MAX)
		{
			cout << -1;
			return 0;
		}
		ans.push_back(idx);
	}
	for (ll i = n - 1; i >= 1; --i)
	{
		ll pivot = ans.back();
		ll id = dp[i + 1][pivot];
		ll nxt = (pivot + 1 <= m) ? (pivot + 1) : -1;
		ll prev = (pivot - 1 >= 1) ? (pivot - 1) : -1;
		ll idx = INT_MAX, maxi = -1;
		for (ll j = 1; j <= m; ++j)
		{
			if (dp[i][j] > maxi && dp[i][j] == id)
			{
				idx = j;
				maxi = dp[i][j];
			}
			else if (dp[i][j] == maxi && dp[i][j] == id)
			{
				idx = min(idx, j);
			}
		}
		if (nxt != -1)
		{
			ll temp = dp[i][nxt];
			if (temp + 1 == id && nxt < idx)
			{
				maxi = temp;
				idx = nxt;
			}
		}
		if (prev != -1)
		{
			ll temp = dp[i][prev];
			if (temp + 1 == id && prev < idx)
			{
				maxi = temp;
				idx = prev;
			}
		}
		if (idx == INT_MAX || maxi == -1 || llabs(id - maxi) > 1)
		{
			cout << -1;
			return 0;
		}
		ans.push_back(idx);
	}
	cout << dp[n][ans.front()] << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}