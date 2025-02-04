#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	auto getter = [&]
		{
			vector<vector<ll>>temp(n + 1, vector<ll>(n + 1, 0));
			return temp;
		};
	vector<vector<ll>>v = getter(), a = getter(), b = getter();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> v[i][j];
			v[i][j] = v[i][j] + v[i][j - 1];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			a[i][j] = a[i - 1][j - 1] + v[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			b[j][i] = b[j - 1][i] + v[j][i];
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int x = 0, y = 0, z = 0;
		cin >> x >> y >> z;
		int ex = x + z - 1, ey = y + z - 1;
		ll ans = a[ex][ey];
		if (x - 1 >= 1 && y - 1 >= 1)
		{
			ans -= a[x - 1][y - 1];
		}
		if (y - 1 >= 1)
		{
			ans -= b[ex][y - 1];
			if (x - 1 >= 1)
			{
				ans += b[x - 1][y - 1];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}