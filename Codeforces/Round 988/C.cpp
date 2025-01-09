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
		ll n = 0;
		cin >> n;
		if (n <= 4)
		{
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= n; i += 2)
		{
			if (i == 5)
			{
				continue;
			}
			cout << i << ' ';
		}
		cout << 5 << ' ' << 4 << ' ';
		for (int i = 2; i <= n; i += 2)
		{
			if (i == 4)
			{
				continue;
			}
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
