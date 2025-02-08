#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>fact(n + 1, 1), inv(n + 1, 0), two(n + 1, 0);
	for (ll i = 2; i <= n; ++i)
	{
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	}
	auto cal = [&](ll a, ll mod)
		{
			ll res = 1;
			a %= MOD;
			while (mod)
			{
				if (mod & 1)
				{
					res = (res * a) % MOD;
				}
				a = (a * a) % MOD;
				mod >>= 1;
			}
			return res;
		};
	ll ans = fact[n];
	for (int i = 0; i < m; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (!inv[temp])
		{
			inv[temp] = (1LL * cal(fact[temp], MOD - 2)) % MOD;
		}
		if (!two[temp])
		{
			two[temp] = (1LL * cal(2, temp - 1)) % MOD;
		}
		ans = (1LL * ans * inv[temp]) % MOD;
		ans = (1LL * ans * two[temp]) % MOD;
	}
	cout << ans;
	return 0;
}