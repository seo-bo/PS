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
		ll n = 0, m = 0;
		cin >> n >> m;
		ll a = min(n, m), b = max(n, m);
		if (a == 1 || b == 1)
		{
			cout << "YES" << '\n';
			continue;
		}
		if ((b - a) % 2)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}