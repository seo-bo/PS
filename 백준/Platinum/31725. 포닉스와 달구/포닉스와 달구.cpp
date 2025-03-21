#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<ll>>up(n + 1, vector<ll>(n + 1, -1));
	vector<vector<ll>>down(n + 1, vector<ll>(n + 1, -1));
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	function<ll(int, int)> d1 = [&](int x, int y)
		{
			if (!(x >= 1 && x <= n && y >= 1 && y <= n))
			{
				return 0LL;
			}
			if (x == n && y == n)
			{
				return (ll)v[x][y];
			}
			if (up[x][y] != -1)
			{
				return up[x][y];
			}
			ll res = 0;
			res = max({ res, d1(x + 1, y) + v[x][y], d1(x, y + 1) + v[x][y] });
			return up[x][y] = res;
		};
	function<ll(int, int)> d2 = [&](int x, int y)
		{
			if (!(x >= 1 && x <= n && y >= 1 && y <= n))
			{
				return 0LL;
			}
			if (x == 1 && y == 1)
			{
				return (ll)v[x][y];
			}
			if (down[x][y] != -1)
			{
				return down[x][y];
			}
			ll res = 0;
			res = max({ res, d2(x - 1, y) + v[x][y], d2(x, y - 1) + v[x][y] });
			return down[x][y] = res;
		};
	d1(1, 1);
	d2(n, n);
	up[n][n] = v[n][n];
	down[1][1] = v[1][1];
	vector<vector<ll>>sum(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			sum[i][j] = up[i][j] + down[i][j] - v[i][j];
		}
	}
	vector<vector<ll>>col(n + 2, vector<ll>(n + 2)), row(n + 2, vector<ll>(n + 2));
	for (int i = 1; i <= n; ++i)
	{
		col[i][1] = sum[i][1];
		for (int j = 2; j <= n; ++j)
		{
			col[i][j] = max(col[i][j - 1], sum[i][j]);
		}
	}
	for (int j = 1; j <= n; ++j)
	{
		row[1][j] = sum[1][j];
		for (int i = 2; i <= n; ++i)
		{
			row[i][j] = max(row[i - 1][j], sum[i][j]);
		}
	}
	ll ans = LLONG_MAX;
	auto check = [&](int x, int y)
		{
			if (x == 1 && y == 1)
			{
				return false;
			}
			if (x == n - k + 1 && y == n - k + 1)
			{
				return false;
			}
			return true;
		};
	for (int i = 1; i <= n - k + 1; ++i)
	{
		for (int j = 1; j <= n - k + 1; ++j) // (1,1) / (n,n) ban
		{
			if (!check(i, j))
			{
				continue;
			}
			ll a = 0, b = 0;
			if (i <= n - k)
			{
				a = max(a, col[i + k][j - 1]);
			}
			if (j <= n - k)
			{
				b = max(b, row[i - 1][j + k]);
			}
			ans = min(ans, max(a, b));
		}
	}
	cout << ans;
	return 0;
}