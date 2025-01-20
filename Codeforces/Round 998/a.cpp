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
		ll a = 0, b = 0, d = 0, e = 0;
		cin >> a >> b >> d >> e;
		auto cal = [&](ll c)
			{
				int cnt = 0;
				if (c == a + b)
				{
					cnt++;
				}
				if (d == b + c)
				{
					cnt++;
				}
				if (e == c + d)
				{
					cnt++;
				}
				return cnt;
			};
		ll ans = 0;
		for (ll i = -100; i <= 200; ++i)
		{
			ans = max(ans, (ll)cal(i));
		}
		cout << ans << '\n';
	}
	return 0;
}
