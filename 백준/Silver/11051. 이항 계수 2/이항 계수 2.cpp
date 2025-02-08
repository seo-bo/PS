#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n = 0, k = 0, ans =1 , de = 1;
	cin >> n >> k;
	for (ll i = 1; i <= n; ++i)
	{
		ans = (ans * i) % MOD;
		if (i <= n - k)
		{
			de = (de * i) % MOD;
		}
		if (i <= k)
		{
			de = (de * i) % MOD;
		}
	}
	auto xgcd = [&](ll a)
		{
			ll temp = 1, ep = MOD - 2;
			while (ep)
			{
				if (ep & 1)
				{
					temp = (temp * a) % MOD;
				}
				a = (a * a) % MOD;
				ep /= 2;
			}
			return temp;
		};
	cout << ans * xgcd(de) % MOD;
	return 0;
}