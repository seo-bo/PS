#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n), up, down;
	for (auto& i : v)
	{
		cin >> i;
	}
	for (ll i = 1; i < n - 1; ++i)
	{
		if (v[i - 1] < v[i] && v[i] > v[i + 1])
		{
			up.push_back(i);
		}
		else if (v[i - 1] > v[i] && v[i] < v[i + 1])
		{
			down.push_back(i);
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= n - 4; ++i)
	{
		ll aa = 0, bb = 0, cc = 0;
		if (v[i] >= v[i + 1])
		{
			continue;
		}
		auto i1 = lower_bound(up.begin(), up.end(), i + 1);
		if (i1 == up.end())
		{
			continue;
		}
		aa = *i1;
		auto i2 = lower_bound(down.begin(), down.end(), aa + 1);
		if (i2 == down.end())
		{
			continue;
		}
		bb = *i2;
		auto i3 = lower_bound(up.begin(), up.end(), bb + 1);
		if (i3 == up.end())
		{
			cc = n - 1;
		}
		else
		{
			cc = *i3;
		}
		bb = max(i + 3, bb + 1);
		if (bb <= cc)
		{
			ans += cc - bb + 1;
		}
	}
	cout << ans;
	return 0;
}
