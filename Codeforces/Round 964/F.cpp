#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";
#define MOD 1000000007

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll>fact(200002,1), inv_fact(200002, 1);
	auto mp = [&](ll b, ll e, ll p)
		{
			ll res = 1;
			while (e > 0)
			{
				if (e % 2)
				{
					res = (res * b) % p;
				}
				b = (b * b) % p;
				e /= 2;
			}
			return res;
		};
	fact[0] = inv_fact[0] = 1;
	for (ll i = 2; i <= 200000; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	inv_fact[199999] = mp(fact[199999], MOD - 2, MOD);
	for (ll i = 199998; i >= 1; --i)
	{
		inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
	}
	auto cmb = [&](ll n, ll k) -> ll
		{
			if (k > n)
			{
				return 0;
			}
			if (k == 0 || k == n)
			{
				return 1;
			}
			return (fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD);
		};
	ll T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0, ones = 0, ans = 0;
		cin >> n >> k;
		vector<ll> a(n);
		for (ll i = 0; i < n; ++i)
		{
			cin >> a[i];
			if (a[i] == 1)
			{
				ones++;
			}
		}
		ll m = (k + 1) / 2;
		for (ll i = m; i <= min(ones, k); ++i)
		{
			ll temp = (cmb(ones, i) * cmb(n - ones, k - i)) % MOD;
			ans = (ans + temp) % MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}
