#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, q = 0;
	cin >> n >> q;
	vector<pll>v;
	for (ll i = 1; i <= n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		v.push_back(make_pair(temp, i));
	}
	vector<tp>Q(q);
	for (ll i = 0; i < q; ++i)
	{
		auto& [a, b, c] = Q[i];
		cin >> a >> b;
		c = i;
	}
	sort(v.begin(), v.end(), [&](const pll& a, const pll& b)
		{
			return a.first < b.first;
		});
	sort(Q.begin(), Q.end(), [&](const tp& a, const tp& b)
		{
			return get<1>(a) < get<1>(b);
		});
	vector<ll>BIT(n + 1);
	auto update = [&](ll idx, ll delta)
		{
			while (idx <= n)
			{
				BIT[idx] = max(BIT[idx], delta);
				idx += idx & -idx;
			}
		};
	auto query = [&](ll idx)
		{
			ll res = 0;
			while (idx > 0)
			{
				res = max(res, BIT[idx]);
				idx -= idx & -idx;
			}
			return res;
		};
	vector<ll>ans(q + 1, 0);
	ll jdx = 0, idx = 0;
	while (idx < q)
	{
		auto& [a, b, c] = Q[idx];
		while (jdx < n && v[jdx].first <= b)
		{
			vector<ll>temp;
			ll pivot = v[jdx].first;
			while (jdx < n && v[jdx].first == pivot)
			{
				temp.push_back(v[jdx].second);
				jdx++;
			}
			vector<ll>p;
			for (auto& i : temp)
			{
				p.push_back(query(i - 1) + 1);
			}
			for (ll i = 0; i < (ll)p.size(); ++i)
			{
				update(temp[i], p[i]);
			}
		}
		ans[c] = query(a);
		idx++;
	}
	for (ll i = 0; i < q; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
