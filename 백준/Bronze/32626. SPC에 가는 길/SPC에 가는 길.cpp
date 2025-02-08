#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	cin >> a >> b >> c >> d >> e >> f;
	if (a == c)
	{
		if (a == e && min(b, d) < f && f < max(b, d))
		{
			cout << 2;
		}
		else
		{
			cout << 0;
		}
	}
	else if (b == d)
	{
		if (b == f && min(a, c) < e && e < max(a, c))
		{
			cout << 2;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 1;
	}
	return 0;
}