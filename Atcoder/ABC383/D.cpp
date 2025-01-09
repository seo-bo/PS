#include <bits/stdc++.h>
#define MAX 2000000
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<bool> ok(MAX + 1, true);
	vector<ll> prime;
	ok[0] = ok[1] = false;
	for (ll i = 2; i * i <= MAX; ++i)
	{
		if (ok[i])
		{
			prime.push_back(i);
			for (ll j = i * i; j <= MAX; j += i)
			{
				ok[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAX; ++i)
	{
		if (ok[i] && i > (ll)sqrt(MAX))
		{
			prime.push_back(i);
		}
	}
	ll cnt = 0;
	for (auto& i : prime)
	{
		ll temp = 1;
		bool flag = true;
		for (int j = 0; j < 8; ++j)
		{
			if (temp > n / i)
			{
				flag = false;
				break;
			}
			temp *= i;
		}
		if (flag && temp <= n)
		{
			cnt++;
		}
		if (i > pow(n, (1.0 / 8)))
		{
			break;
		}
	}
	ll ans = 0;
	for (int i = 0; i < prime.size(); ++i)
	{
		ll temp = prime[i] * prime[i];
		if (temp > n)
		{
			break;
		}
		ll s1 = floor(sqrt(n));
		ll s2 = floor(s1 / prime[i]);
		if (s2 < prime[i])
		{
			continue;
		}
		int lidx = i + 1;
		int uidx = upper_bound(prime.begin(), prime.end(), s2) - prime.begin() - 1;
		if (uidx >= lidx)
		{
			ans += uidx - lidx + 1LL;
		}
	}
	cout << ans + cnt;
	return 0;
}
