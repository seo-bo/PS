#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	auto cal = [&](ll a)
		{
			ll res = 0;
			for (ll i = 0; i < 60; ++i)
			{
				ll p = (1LL << i);
				res += p * ((a + 1) / (p * 2)) + max(0LL, ((a + 1) % (p * 2)) - p);
			}
			return res;
		};
	cout << cal(b) - cal(a - 1);
	return 0;
}