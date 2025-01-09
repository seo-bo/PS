#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, q = 0, suma = 0, sumb = 0;
	cin >> n >> m >> q;
	vector<ll>a(n + 1), b(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		suma += a[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> b[i];
		sumb += b[i];
	}
	auto ps = [&](ll p)
		{
			return p + 200000;
		};
	vector<ll>pa(400020, 0), pb(400020, 0);
	for (int i = 1; i <= n; ++i)
	{
		ll pivot = suma - a[i];
		if (-200000 <= pivot && pivot <= 200000)
		{
			pa[ps(pivot)]++;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		ll pivot = b[i];
		if (-200000 <= pivot && pivot <= 200000)
		{
			pb[ps(pivot)]++;
		}
	}
	auto divs = [&](ll pp)
		{
			vector<ll>div;
			pp = llabs(pp);
			for (ll i = 1; i * i <= pp && i <= 200000; ++i)
			{
				if (pp % i)
				{
					continue;
				}
				div.push_back(i);
				div.push_back(-i);
				ll dd = pp / i;
				if (dd != i && dd <= 200000)
				{
					div.push_back(dd);
					div.push_back(-dd);
				}
			}
			return div;
		};
	while (q--)
	{
		ll x = 0, ans = 0;
		cin >> x;
		ll piv = suma * sumb - x;
		vector<ll>div = divs(x);
		for (auto& i : div)
		{
			ll cei = sumb - x / i;
			if (cei < -200000 || cei > 200000)
			{
				continue;
			}
			ans += pa[ps(i)] * pb[ps(cei)];
		}
		cout << ((ans) ? "YES" : "NO") << '\n';
	}
	return 0;
}
