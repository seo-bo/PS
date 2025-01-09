#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<vector<ll>>v(11);
	for (ll i = 1; i <= n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		v[b].push_back(a);
	}
	vector<vector<ll>>prefix(11, vector<ll>(1, 0));
	for (ll i = 1; i <= 10; ++i)
	{
		if (!v[i].empty())
		{
			sort(v[i].rbegin(), v[i].rend());
			for (ll j = 0; j < v[i].size(); ++j)
			{
				prefix[i].push_back(prefix[i].back() + v[i][j] + 2 * j);
			}
		}
	}
	vector<vector<ll>>dp(11, vector<ll>(k + 1, -1));
	function<ll(ll, ll)> dfs = [&](ll depth, ll cnt)
		{
			if (depth > 10)
			{
				return 0LL;
			}
			if (dp[depth][cnt] != -1)
			{
				return dp[depth][cnt];
			}
			ll res = dfs(depth + 1, cnt);
			for (ll i = 1; i < prefix[depth].size(); ++i)
			{
				if (cnt >= i)
				{
					res = max(res, prefix[depth][i] + dfs(depth + 1, cnt - i));
				}
			}
			return dp[depth][cnt] = res;
		};
	cout << dfs(1, k);
	return 0;
}