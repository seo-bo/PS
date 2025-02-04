#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	vector<pll>p(m);
	for (auto& [a, b] : p)
	{
		cin >> a >> b;
	}
	ll x = 0, y = 0, ans = 0, idx = 0;
	auto sv = [&](ll a, ll b, ll c, ll d)
		{
			return (a - c) * (a - c) + (b - d) * (b - d);
		};
	for (int i = 0; i < m; ++i)
	{
		ll pivot = -1, tdx = -1;
		for (int j = 0; j < v.size(); ++j)
		{
			auto [xx, yy] = v[j];
			ll temp = sv(x, y, xx, yy);
			if (temp > pivot)
			{
				pivot = temp;
				tdx = j;
			}
		}
		ans += pivot;
		x = v[tdx].first;
		y = v[tdx].second;
		v.erase(v.begin() + tdx);
		if (idx < m)
		{
			v.push_back(p[idx++]);
		}
	}
	cout << ans;
	return 0;
}