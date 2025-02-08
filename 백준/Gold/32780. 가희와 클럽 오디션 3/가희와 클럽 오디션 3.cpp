#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll> fact(n + 1, 1), inv(n + 1, 1);
	auto power = [&](ll base, ll p)
		{
			ll res = 1;
			while (p > 0)
			{
				if (p & 1)
				{
					res = (res * base) % MOD;
				}
				base = (base * base) % MOD;
				p >>= 1;
			}
			return res;
		};
	for (ll i = 2; i <= n; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	inv[n] = power(fact[n], MOD - 2);
	for (ll i = n - 1; i >= 1; --i)
	{
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	}
	auto comb = [&](ll a, ll b)
		{
			if (b > a || b < 0)
			{
				return 0LL;
			}
			return fact[a] * inv[b] % MOD * inv[a - b] % MOD;
		};
	ll ans = 0;
	if (n <= 5)
	{
		ans = power(4, n);
	}
	else
	{
		for (ll i = 0; i <= min(6LL, n); ++i)
		{
			ll temp = comb(n, i) * power(8, i) % MOD * power(8, n - i) % MOD;
			ans = (ans + temp) % MOD;
		}
	}
	cout << ans;
	return 0;
}