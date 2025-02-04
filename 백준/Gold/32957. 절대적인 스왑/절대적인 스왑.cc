#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, sum = 0;
	cin >> n;
	vector<ll>v(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
		sum += llabs(v[i] - i);
	}
	vector<pll>a(n + 1), b(n + 1), c(n + 1), d(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		a[i] = make_pair(v[i] - i, i);
		b[i] = make_pair(v[i] + i, i);
		c[i] = make_pair(-v[i] + i, i);
		d[i] = make_pair(-v[i] - i, i);
	}
	auto sv = [&](vector<pll>& vv)
		{
			sort(vv.begin() + 1, vv.end());
			vector<ll>temp;
			for (ll i = 1; i <= min(15LL, n); ++i)
			{
				temp.push_back(vv[i].second);
			}
			for (ll i = max(1LL, n - 15LL + 1); i <= n; ++i)
			{
				temp.push_back(vv[i].second);
			}
			return temp;
		};
	vector<ll>p1 = sv(a);
	vector<ll>p2 = sv(b);
	vector<ll>p3 = sv(c);
	vector<ll>p4 = sv(d);
	set<ll>ss;
	for (auto& i : p1)
	{
		ss.insert(i);
	}
	for (auto& i : p2)
	{
		ss.insert(i);
	}
	for (auto& i : p3)
	{
		ss.insert(i);
	}
	for (auto& i : p4)
	{
		ss.insert(i);
	}
	vector<ll>res(ss.begin(), ss.end());
	ll ans = 0;
	ll len = res.size();
	for (ll i = 0; i < len; ++i)
	{
		for (ll j = 0; j < len; ++j)
		{
			if (i == j)
			{
				continue;
			}
			ll s1 = llabs(v[res[i]] - res[i]) + llabs(v[res[j]] - res[j]);
			ll s2 = llabs(v[res[j]] - res[i]) + llabs(v[res[i]] - res[j]) - s1;
			ans = max(ans, s2);
		}
	}
	cout << ans + sum;
	return 0;
}