#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<pll>v;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a > b)
		{
			v.push_back(make_pair(b, a));
		}
	}
	if (v.empty())
	{
		cout << m;
		return 0;
	}
	sort(v.begin(), v.end());
	auto& [st, ed] = v[0];
	ll ans = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		auto [ns, ne] = v[i];
		if (ns <= ed)
		{
			ed = max(ed, ne);
		}
		else
		{
			ans += ed - st;
			st = ns, ed = ne;
		}
	}
	ans += ed - st;
	cout << m + ans * 2LL;
	return 0;
}