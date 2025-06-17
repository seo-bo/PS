#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, ans = 0;
		cin >> n;
		ll st = max(1LL, n - 3);
		for (ll i = st; i <= n; ++i)
		{
			for (ll j = i + 1; j <= n; ++j)
			{
				for (ll k = j + 1; k <= n; ++k)
				{
					ans = max(ans, lcm(i, lcm(j, k)));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}