#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		ll ans = a;
		if (b % 3)
		{
			if (c < 3 - (b % 3))
			{
				cout << -1 << "\n";
				continue;
			}
			ans += b / 3 + 1;
			c -= 3 - (b % 3);
			b = 0;
		}
		else
		{
			ans += b / 3;
			b = 0;
		}
		ans += c / 3;
		c %= 3;
		ans += c / 2;
		c %= 2;
		ans += c;
		cout << ans << '\n';
	}
	return 0;
}
