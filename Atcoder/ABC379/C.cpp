#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>X(m), A(m);
	for (auto& i : X)
	{
		cin >> i;
	}
	ll sum = 0;
	for (auto& i : A)
	{
		cin >> i;
		sum += i;
	}
	if (sum != n)
	{
		cout << -1;
		return 0;
	}
	vector<pll>v;
	for (int i = 0; i < m; ++i)
	{
		v.push_back(make_pair(X[i], A[i]));
	}
	sort(v.begin(), v.end());
	vector<pll>temp;
	ll pre = 0;
	for (auto& [a, b] : v)
	{
		if (pre + 1 <= a - 1)
		{
			temp.push_back(make_pair(pre + 1, a - 1));
		}
		pre = a;
	}
	if (pre + 1 <= n)
	{
		temp.push_back(make_pair(pre + 1, n));
	}
	ll ans = 0, cura = 0, curb = 0;
	int idx = 0;
	if (idx < temp.size())
	{
		cura = temp[idx].first;
		curb = temp[idx].second;
	}
	for (auto& [x, oe] : v)
	{
		ll e = oe - 1;
		while (e > 0 && idx < temp.size())
		{
			auto [a, b] = temp[idx];
			ll pp = max(a, x);
			if (pp > b)
			{
				idx++;
				continue;
			}
			ll k = min(e, b - pp + 1);
			ans += k * (pp - x) + (k * (k - 1)) / 2;
			e -= k;
			pp += k;
			if (pp > b)
			{
				idx++;
			}
			else
			{
				temp[idx].first = pp;
			}
		}
		if (e > 0)
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
