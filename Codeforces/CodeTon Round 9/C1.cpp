#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto cal = [&](ll x)
		{
			vector<ll>div;
			for (ll i = 1; i * i <= x; ++i)
			{
				if (!(x % i))
				{
					div.push_back(i);
					if (x / i != i)
					{
						div.push_back(x / i);
					}
				}
			}
			return div;
		};
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll x = 0, m = 0;
		cin >> x >> m;
		vector<ll>v = cal(x);
		ll ans = 0;
		vector<ll>s;
		for (auto& i : v)
		{
			ll p = x ^ i;
			if (p >= 1 && p <= m && p != x)
			{
				ans++;
			}
		}
		for (ll i = 1; i <= x; ++i)
		{
			ll p = x ^ i;
			if (p < 1 || p > m || p == x)
			{
				continue;
			}
			if (!(p % i) && (x % i))
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
