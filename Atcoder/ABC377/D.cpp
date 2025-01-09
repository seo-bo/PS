#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(m + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (b <= m)
		{
			v[b] = max(v[b], a);
		}
	}
	for (int i = 2; i <= m; ++i)
	{
		v[i] = max(v[i], v[i - 1]);
	}
	ll ans = 0;
	for (ll i = 1; i <= m; ++i)
	{
		ans += i - v[i];
	}
	cout << ans;
	return 0;
}
