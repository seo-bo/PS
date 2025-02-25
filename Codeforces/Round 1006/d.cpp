#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0;
		cin >> n;
		vector<ll>v(n + 1);
		for (ll i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		ll left = 1, right = 1, ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			ll pa = 0, pb = 0;
			for (int j = i + 1; j <= n; ++j)
			{
				if (v[i] > v[j])
				{
					pa++;
				}
				else if (v[i] < v[j])
				{
					pb++;
				}
				if (ans > pb - pa)
				{
					ans = pb - pa;
					left = i;
					right = j;
				}
			}
		}
		cout << left << ' ' << right << '\n';
	}
	return 0;
}
