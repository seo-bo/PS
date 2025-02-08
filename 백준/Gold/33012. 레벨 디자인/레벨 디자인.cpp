#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	ll mid = n / 2;
	vector<ll>v(n, 0);
	for (ll i = 0; i < n; ++i)
	{
		v[i] = n - i;
	}
	vector<ll>order;
	if (n % 2 == 0)
	{
		mid--;
	}
	order.push_back(mid);
	for (ll i = 1; i <= max(mid, n - mid - 1); ++i)
	{
		if (mid - i >= 0)
		{
			order.push_back(mid - i);
		}
		if (mid + i < n)
		{
			order.push_back(mid + i);
		}
	}
	vector<ll>s(n, 0);
	for (ll i = 0; i < n; ++i)
	{
		if (i < order.size())
		{
			s[order[i]] = v[i];
		}
	}
	ll p1 = 0, p2 = 0;
	if (n >= 2)
	{
		p1 = max(s[0], s[1]);
	}
	p2 = s[0];
	for (ll i = 2; i < n; ++i)
	{
		ll cur = max(p1, p2 + s[i]);
		p2 = p1;
		p1 = cur;
	}
	ll ans = p2;
	if (n >= 2)
	{
		ans = p1;
	}
	for (ll i = 0; i < n; ++i)
	{
		cout << s[i] << ' ';
	}
	cout << '\n';
	cout << ans;
	return 0;
}