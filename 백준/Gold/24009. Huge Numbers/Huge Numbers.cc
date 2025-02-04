#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	for (int _ = 1; _ <= T; ++_)
	{
		ll a = 0, n = 0, p = 0;
		cin >> a >> n >> p;
		auto power = [&](ll base, ll exp)
			{
				ll res = 1;
				while (exp > 0)
				{
					if (exp & 1)
					{
						res = (res * base) % p;
					}
					base = (base * base) % p;
					exp >>= 1;
				}
				return res;
			};
		ll ans = a;
		for (ll i = 2; i <= n && ans; ++i)
		{
			ans = power(ans, i);
		}
		cout << format("Case #{}: {}\n", _, ans % p);
	}
	return 0;
}