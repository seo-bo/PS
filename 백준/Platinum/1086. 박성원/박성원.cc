#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, ans = 1, k = 0;
	cin >> n;
	for (ll i = 2; i <= n; ++i)
	{
		ans *= i;
	}
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	cin >> k;
	vector<ll>plus(n), len(n);
	for (int i = 0; i < n; ++i)
	{
		ll mod = 0, siz = 1;
		for (auto& a : v[i])
		{
			mod = (mod * 10 + (a - '0')) % k;
			siz = (siz * 10) % k;
		}
		plus[i] = mod;
		len[i] = siz;
	}
	vector<vector<ll>>dp(1LL << n, vector<ll>(k + 1, -1));
	function<ll(ll, ll)> dfs = [&](ll mask, ll mod)
		{
			if (mask == (1LL << n) - 1)
			{
				return (mod % k) ? 0LL : 1LL;
			}
			if (dp[mask][mod] != -1)
			{
				return dp[mask][mod];
			}
			ll cost = 0;
			for (int i = 0; i < n; ++i)
			{
				if (!(mask & (1LL << i)))
				{
					cost += dfs(mask | (1LL << i), (mod * len[i] + plus[i]) % k);
				}
			}
			return dp[mask][mod] = cost;
		};
	ll res = dfs(0, 0);
	if (res == 0)
	{
		cout << "0/1";
		return 0;
	}
	ll mod = gcd(res, ans);
	cout << res / mod << '/' << ans / mod;
	return 0;
}