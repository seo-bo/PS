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
		ll n = 0;
		cin >> n;
		ll ans = 0;
		for (ll i = (n - 1) / 2; i >= (n + 2) / 3; --i)
		{
			if (i == (n / 3))
			{
				ans++;
			}
			else if (!((n - i) % 2))
			{
				ans += 2 * (i - (n - i + 1) / 2 - 1) + 2;
			}
			else
			{
				ans += 2 * (i - (n - i + 1) / 2) + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}