#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll x = 0, q = 0;
	cin >> x >> q;
	vector<ll>ans(100005, 0);
	ans[0] = x;
	for (ll i = 1; i <= 100000; ++i)
	{
		ans[i] = i * ((ans[i - 1] + i) / i);
	}
	ll term = ans[100000] - ans[99999];
	while (q--)
	{
		ll a = 0;
		cin >> a;
		if (a <= 100000)
		{
			cout << ans[a] << '\n';
		}
		else
		{
			cout << ans[100000] + (term * (a - 100000)) << '\n';
		}
	}
	return 0;
}