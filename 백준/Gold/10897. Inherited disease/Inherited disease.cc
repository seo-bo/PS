#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll d = 0;
	cin >> d;
	ll cur = 1, tot = 1, pivot = 1;
	for (ll i = 1; i <= d; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (i == 1)
		{
			cout << 1 << '\n';
			continue;
		}
		ll res = (tot + (cur - 1LL) * i + temp) % MOD;
		cout << res << '\n';
		cur = (res - tot + MOD) % MOD;
		pivot = (pivot * i) % MOD;
		tot = (tot + pivot) % MOD;
	}
	return 0;
}
