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
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		auto xo = [&](ll p)
			{
				if (p < 0)
				{
					return 0LL;
				}
				ll m = p % 4;
				if (m == 0)
				{
					return p;
				}
				else if (m == 1)
				{
					return 1LL;
				}
				else if (m == 2)
				{
					return p + 1LL;
				}
				return 0LL;
			};
		ll pivot = xo(a - 1) ^ xo(b);
		ll power = 1LL << c;
		ll mini = 0, maxi = -1, p = 0;
		if (a > d)
		{
			mini = (a - d + power - 1) / power;
		}
		if (b >= d)
		{
			maxi = (b - d) / power;
		}
		if (maxi >= mini)
		{
			p = maxi - mini + 1LL;
		}
		ll other = 0;
		if (p > 0)
		{
			other = ((xo(maxi) ^ xo(mini - 1)) << c);
			if (p % 2)
			{
				other ^= d;
			}
		}
		cout << (pivot ^ other) << '\n';
	}
	return 0;
}
