#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0, c = 0, ans = LLONG_MAX;
	cin >> a >> b >> c;
	for (ll i = 1; i <= 1000000; ++i)
	{
		ll p1 = c / i;
		ll p2 = p1 + 1;
		for (auto& j : { p1,p2 })
		{
			if (j >= 1 && j <= 1000000)
			{
				ll ab = i * j;
				ans = min(ans, abs(i - a) + abs(j - b) + abs(ab - c));
				if (!ans)
				{
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}