#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll MAX = 1e6;
	vector<bool>ban(MAX + 1, true);
	ban[0] = ban[1] = false;
	vector<ll>prime;
	for (ll i = 2; i <= MAX; ++i)
	{
		if (ban[i])
		{
			prime.push_back(i);
			for (ll j = i * i; j <= MAX; j += i)
			{
				ban[j] = false;
			}
		}
	}
	set<ll>ok;
	int len = prime.size();
	for (int i = 0; i < len; ++i)
	{
		ll a = prime[i];
		while (a <= MAX)
		{
			for (int j = i + 1; j < len; ++j)
			{
				ll b = prime[j];
				if (b > MAX / a)
				{
					break;
				}
				while (a <= MAX / b)
				{
					ok.insert(a * a * b * b);
					if (MAX / b < prime[j])
					{
						break;
					}
					b *= prime[j];
				}
			}
			if (MAX / a < prime[i])
			{
				break;
			}
			a *= prime[i];
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0;
		cin >> a;
		auto it = ok.upper_bound(a);
		cout << *prev(it) << '\n';
	}
	return 0;
}
