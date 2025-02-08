#include <bits/stdc++.h>
#define m 1300000
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<bool>prime(1300001, true);
	prime[0] = prime[1] = false;
	vector<ll>v;
	for (ll i = 2; i <= m; ++i)
	{
		if (prime[i])
		{
			v.push_back(i);
			for (ll j = i * i; j <= m; j += i)
			{
				prime[j] = false;
			}
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int temp = 0;
		cin >> temp;
		if (prime[temp])
		{
			cout << 0 << '\n';
			continue;
		}
		auto it = upper_bound(v.begin(), v.end(), temp);
		auto jt = prev(it);
		cout << *it - *jt << '\n';
	}
	return 0;
}
