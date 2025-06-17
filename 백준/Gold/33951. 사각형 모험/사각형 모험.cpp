#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<vector<char>>v(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; ++j)
		{
			v[i][j] = str[j - 1];
		}
	}
	vector<vector<int>>dp1(n + 1, vector<int>(m + 1, -1));
	vector<vector<int>>dp2(n + 1, vector<int>(m + 1, -1));
	function<int(int, int)> dfs1 = [&](int x, int y) // 최소
		{
			if (x > n || y > m)
			{
				return (1 << 20);
			}
			if (x == n && y == m)
			{
				return (int)(v[x][y] == 'A');
			}
			if (dp1[x][y] != -1)
			{
				return dp1[x][y];
			}
			int res = 1 << 20;
			res = min({ res, dfs1(x + 1, y) + (int)(v[x][y] == 'A'), dfs1(x, y + 1) + (int)(v[x][y] == 'A') });
			return dp1[x][y] = res;
		};
	function<int(int, int)> dfs2 = [&](int x, int y) // 최대
		{
			if (x > n || y > m)
			{
				return -(1 << 20);
			}
			if (x == n && y == m)
			{
				return (int)(v[x][y] == 'A');
			}
			if (dp2[x][y] != -1)
			{
				return dp2[x][y];
			}
			int res = -(1 << 20);
			res = max({ res, dfs2(x + 1, y) + (int)(v[x][y] == 'A'), dfs2(x, y + 1) + (int)(v[x][y] == 'A') });
			return dp2[x][y] = res;
		};
	int ax = dfs1(1, 1), ay = dfs2(1, 1), bx = n + m - 1 - ax, by = n + m - 1 - ay;
	while (q--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == b)
		{
			if ((n + m - 1) * a == c)
			{
				cout << "YES" << '\n';
			}
			else
			{
				cout << "NO" << '\n';
			}
			continue;
		}
		ll px = ax * a + bx * b;
		ll py = ay * a + by * b;
		ll mini = min(px, py), maxi = max(px, py);
		if (mini <= c && c <= maxi && !((c - mini) % llabs(a - b)))
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