#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto power = [&](ll base, ll mod)
		{
			ll res = 1, exp = mod;
			while (exp > 0)
			{
				if (exp & 1)
				{
					res = (res * base) % mod;
				}
				base = (base * base) % mod;
				exp >>= 1;
			}
			return res;
		};
	auto check = [&](ll n)
		{
			if (n == 3)
			{
				return true;
			}
			if (n % 2 == 0 || n % 3 == 0)
			{
				return false;
			}
			for (ll i = 5; i * i <= n; i += 6)
			{
				if (n % i == 0 || n % (i + 2) == 0)
				{
					return false;
				}
			}
			return true;
		};
	while (1)
	{
		ll p = 0, a = 0;
		cin >> p >> a;
		if (p * a == 0)
		{
			break;
		}
		if (check(p))
		{
			cout << "no" << '\n';
			continue;
		}
		cout << (((power(a, p) == a) ? "yes\n" : "no\n"));
	}
	return 0;
}
