#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto power = [&](ll x)
		{
			ll res = 1, p = MOD - 2;
			x %= MOD;
			if (x < 0)
			{
				x += MOD;
			}
			while (p > 0)
			{
				if (p & 1)
				{
					res = (res * x) % MOD;
				}
				x = (x * x) % MOD;
				p >>= 1;
			}
			return res;
		};
	ll n = 0, q = 0;
	cin >> n >> q;
	vector<ll>v(n + 1, 0), prefix(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	vector<ll>imos(n + 2, 0);
	while (q--)
	{
		ll l = 0, r = 0;
		cin >> l >> r;
		ll pivot = prefix[r] - prefix[l - 1];
		ll inv = power(pivot);
		imos[l] = (imos[l] + inv) % MOD;
		imos[r + 1] = (imos[r + 1] - inv) % MOD;
		if (imos[r + 1] < 0)
		{
			imos[r + 1] += MOD;
		}
	}
	vector<ll>pre(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		pre[i] = (pre[i - 1] + imos[i]) % MOD;
	}
	vector<ll>ans(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		if (v[i] >= 2)
		{
			ans[i] = (((v[i] * (v[i] - 1)) % MOD) * pre[i]) % MOD;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}