#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0;
		cin >> n >> k;
		if (n == 1)
		{
			cout << k << '\n';
			continue;
		}
		auto cal = [&](ll a)
			{
				ll res = 0;
				while (a)
				{
					res += a >> 1;
					a >>= 1;
				}
				return res;
			};
		cout << k << ' ';
		for (ll i = 2; i <= n - 1; ++i)
		{
			ll pivot = cal(n - 1) - cal(i - 1) - cal(n - i);
			cout << ((pivot) ? 0 : k) << ' ';
		}
		cout << k << '\n';
	}
	return 0;
}
