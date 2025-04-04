#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, q = 0;
	cin >> n;
	vector<ll>v(n + 2);
	v[0] = LLONG_MIN;
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	v[n + 1] = LLONG_MAX;
	cin >> q;
	while (q--)
	{
		ll t = 0, p = 0;
		cin >> t >> p;
		auto it = upper_bound(v.begin(), v.end(), p) - v.begin() - 1;
		ll st = (v[it] == LLONG_MIN) ? (p - t) : max(v[it] + 1, p - t);
		ll ed = (v[it + 1] == LLONG_MAX) ? (p + t) : min(v[it + 1] - 1, p + t);
		auto cal = [&](ll a, ll b, ll c)
			{
				if (a > b)
				{
					return 0LL;
				}
				ll ta = ((a % 2 + 2) % 2 == c) ? a : a + 1;
				if (ta > b)
				{
					return 0LL;
				}
				ll tb = ((b % 2 + 2) % 2 == c) ? b : b - 1;
				if (ta > tb)
				{
					return 0LL;
				}
				return (tb - ta) / 2 + 1;
			};
		cout << cal(st, ed, ((p + t) % 2 + 2) % 2) << '\n';
	}
	return 0;
}