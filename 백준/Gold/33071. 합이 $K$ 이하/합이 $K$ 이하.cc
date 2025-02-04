#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	sort(v.begin(), v.end(), [&](const pll& a, const pll& b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second < b.second;
		});
	vector<ll>prefixa(n, LLONG_MIN), prefixb(n, LLONG_MIN), ppa(n, LLONG_MIN), ppb(n, LLONG_MIN);
	prefixb[0] = v[0].second;
	prefixa[0] = v[0].first;
	ppa[0] = -1;
	for (int i = 1; i < n; ++i)
	{
		if (v[i].second > prefixb[i - 1])
		{
			ppb[i] = prefixb[i - 1];
			ppa[i] = prefixa[i - 1];
			prefixb[i] = v[i].second;
			prefixa[i] = v[i].first;
		}
		else if (v[i].second > ppb[i - 1])
		{
			ppb[i] = v[i].second;
			ppa[i] = v[i].first;
			prefixb[i] = prefixb[i - 1];
			prefixa[i] = prefixa[i - 1];
		}
		else
		{
			ppb[i] = ppb[i - 1];
			ppa[i] = ppa[i - 1];
			prefixb[i] = prefixb[i - 1];
			prefixa[i] = prefixa[i - 1];
		}
	}
	ll ans = LLONG_MIN;
	for (auto& [a, b] : v)
	{
		ll target = k - b;
		auto it = upper_bound(v.begin(), v.end(), make_pair(0, target), [&](const pll& c, const pll& d)
			{
				return c.second < d.second;
			}) - v.begin() - 1;
		if (it < 0)
		{
			continue;
		}
		if (prefixa[it] != a)
		{
			ll sum = b + prefixb[it];
			if (sum <= k)
			{
				ans = max(ans, sum);
			}
		}
		else
		{
			if (ppb[it] != LLONG_MIN && ppa[it] != a)
			{
				ll sum = b + ppb[it];
				if (sum <= k)
				{
					ans = max(ans, sum);
				}
			}
		}
	}
	if (ans == LLONG_MIN)
	{
		cout << "NO";
	}
	else
	{
		cout << ans;
	}
	return 0;
}