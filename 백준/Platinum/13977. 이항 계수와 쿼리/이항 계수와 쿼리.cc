#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 0;
	vector<ll>fact(4000001, 1);
	cin >> t;
	for (ll i = 1; i <= 4000000; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	auto xgcd = [&](ll a)
		{
			ll ans = 1, ep = MOD - 2;
			while (ep)
			{
				if (ep % 2)
				{
					ans = (ans * a) % MOD;
				}
				a = (a * a) % MOD;
				ep /= 2;
			}
			return ans;
		};
	while (t--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << fact[a] * xgcd((fact[a - b] * fact[b] % MOD)) % MOD << '\n';
	}
	return 0;
}