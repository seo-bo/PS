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
		ll r = 0, c = 0, a = 0, b = 0;
		cin >> r >> c;
		ll x = r, y = c;
		while (x && y)
		{
			a += x * y;
			a += --x * --y;
		}
		x = r, y = c;
		while (x && y)
		{
			b += (x - 1) * y;
			b += (y-- - 1) * x--;
		}
		cout << a << ' ' << b << '\n';
	}
	return 0;
}