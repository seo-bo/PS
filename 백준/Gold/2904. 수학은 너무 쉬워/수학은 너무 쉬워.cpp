#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	map<ll, ll>mm, exp;
	vector<map<ll, ll>>factor;
	auto cal = [&](ll a)
		{
			map<ll, ll>fact;
			for (ll i = 2; i * i <= a; ++i)
			{
				while (a % i == 0)
				{
					fact[i]++;
					a /= i;
				}
			}
			if (a > 1)
			{
				fact[a]++;
			}
			for (auto& [a, b] : fact)
			{
				mm[a] += b;
			}
			factor.push_back(fact);
		};
	for (auto& i : v)
	{
		cal(i);
	}
	for (auto& [a, b] : mm)
	{
		exp[a] = b / n;
	}
	ll g = 1, ans = 0;
	for (auto& [a, b] : exp)
	{
		for (ll i = 0; i < b; ++i)
		{
			g *= a;
		}
	}
	for (ll i = 0; i < n; ++i)
	{
		for (auto& [a, b] : exp)
		{
			ans += max(0LL, (ll)b - factor[i][a]);
		}
	}
	cout << g << ' ' << ans;
	return 0;
}