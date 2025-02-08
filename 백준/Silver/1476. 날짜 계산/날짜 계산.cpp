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
	int e = 0, s = 0, m = 0;
	cin >> e >> s >> m;
	ll ans = 1;
	int a = 1, b = 1, c = 1;
	while (e != a || s != b || m != c)
	{
		a = (a + 1) % 16;
		b = (b + 1) % 29;
		c = (c + 1) % 20;
		if (!a)
		{
			a = 1;
		}
		if (!b)
		{
			b = 1;
		}
		if (!c)
		{
			c = 1;
		}
		ans++;
	}
	cout << ans;
	return 0;
}