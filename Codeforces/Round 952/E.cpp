#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll x = 0, y = 0, z = 0, k = 0, ans = 0;
		cin >> x >> y >> z >> k;
		for (ll i = 1; i <= x; ++i)
		{
			if (k % i)
			{
				continue;
			}
			ll temp = k / i;
			for (ll j = 1; j <= y; ++j)
			{
				if (temp % j)
				{
					continue;
				}
				ll c = temp / j;
				if (c <= z)
				{
					ans = max(ans, (x - i + 1) * (y - j + 1) * (z - c + 1));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
