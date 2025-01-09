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
		ll n = 0, k = 0;
		cin >> n >> k;
		if (n == 1)
		{
			cout << 1 << '\n' << 1 << '\n';
			continue;
		}
		if (k == 1 || k == n)
		{
			cout << -1 << '\n';
			continue;
		}
		cout << 3 << '\n';
		if (k % 2)
		{
			cout << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
		}
		else
		{
			cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
		}
	}
	return 0;
}
