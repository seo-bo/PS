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
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a == b && b == 1)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << b - a << '\n';
		}
	}
	return 0;
}