#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	for (auto& [a, b] : v)
	{
		cin >> b >> a;
		b = (a * b) % MOD;
		a = max(0LL, a - 1);
	}
	sort(v.rbegin(), v.rend());
	auto power = [&](ll base, ll exp)
		{
			ll res = 1;
			while (exp)
			{
				if (exp & 1)
				{
					res = (res * base) % MOD;
				}
				base = (base * base) % MOD;
				exp >>= 1;
			}
			return res;
		};
	ll ans = 0;
	for (auto& [a, b] : v)
	{
		ans = (ans + power(2, a) * b % MOD) % MOD;
	}
	cout << ans;
	return 0;
}