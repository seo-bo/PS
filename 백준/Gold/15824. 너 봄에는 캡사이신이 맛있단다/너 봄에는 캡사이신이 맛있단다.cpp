#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll ans = 0;
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
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		ans = (ans + (v[i] * (power(2, i) - power(2, n - i - 1) + MOD) % MOD) % MOD) % MOD;
	}
	cout << ans;
	return 0;
}