#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void) // [a1, ak+1, a2k+1.....] [a2, ak+2, a2k+2......] [a3, ak+3, a2k+3 ......]
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>fact(n + 1, 1);
	vector<bool>visited(n + 1, false);
	for (ll i = 2; i <= n; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	auto power = [&](ll base)
		{
			ll p = MOD - 2, res = 1;
			base = (base + MOD) % MOD;
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
	ll p = n, ans = 1;
	for (int i = 1; i <= p && n; ++i)
	{
		ll cnt = 0;
		for (int j = i; j <= p && !visited[j]; j += k)
		{
			visited[j] = true;
			cnt++;
		}
		ans = (ans * fact[n]) % MOD;
		ans = (ans * power(fact[n - cnt] * fact[cnt])) % MOD;
		n -= cnt;
	}
	cout << ans;
	return 0;
}