#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	unordered_map<ll, ll>res;
	while (1)
	{
		ll x = 0;
		cin >> x;
		if (!x)
		{
			break;
		}
		if (res.find(x) != res.end())
		{
			cout << res[x] << '\n';
			continue;
		}
		ll p = x * x;
		vector<pll>div;
		for (ll i = 1; i <= x; ++i)
		{
			if (p % i == 0)
			{
				if (p / i == i)
				{
					div.push_back(make_pair(i, i));
				}
				else
				{
					div.push_back(make_pair(i, p / i));
				}
			}
		}
		ll ans = 0;
		auto cal = [&](ll a, ll b)
			{
				ll pivot = a + b;
				if (pivot % 2)
				{
					return false;
				}
				ll c = pivot / 2;
				ll d = c - a;
				if (x < c && x < d)
				{
					return true;
				}
				return false;
			};
		for (auto& [a, b] : div)
		{
			if (cal(a, b))
			{
				ans++;
			}
			if (a != b)
			{
				if (cal(b, a))
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
		res[x] = ans;
	}
	return 0;
}