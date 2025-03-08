#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto power = [&](ll base, ll exp)
		{
			ll res = 1;
			while (exp)
			{
				if (exp & 1)
				{
					res = (res * base) % MOD;
				}
				base = (base * base) % MOD;
				exp >>= 1;
			}
			return res;
		};
	ll n = 0, m = 0, fact = 1;
	cin >> n >> m;
	for (ll i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		fact = (fact * i) % MOD;
	}
	char s;
	cin >> s;
	if (s == 'S')
	{
		cout << power(2LL * n * power(n + 1, MOD - 2) % MOD, m);
		return 0;
	}
	ll a = power(n + 1, MOD - 2) * fact % MOD;
	ll b = n * power(2, MOD - 2) % MOD;
	cout << power(a + b % MOD, m);
	return 0;
}