#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, ans = 0;
	string str;
	cin >> n >> str;
	map<char, ll>mm;
	for (auto& i : str)
	{
		mm[i]++;
	}
	auto power = [&](ll p)
		{
			ll base = 2;
			ll res = 1;
			while (p > 0)
			{
				if (p & 1)
				{
					res = (res * base) % MOD;
				}
				base = (base * base) % MOD;
				p >>= 1;
			}
			return res;
		};
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		if (it->second)
		{
			ans = (ans + (power(it->second) - it->second - 1 + MOD) % MOD) % MOD;
		}
		for (auto jt = next(it); jt != mm.end(); ++jt)
		{
			ans = (ans + it->second * jt->second % MOD) % MOD;
		}
	}
	cout << ans;
	return 0;
}