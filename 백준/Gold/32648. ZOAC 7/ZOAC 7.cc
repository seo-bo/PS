#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<int>>uZ(n, vector<int>(m, -1)), uO(n, vector<int>(m, -1)), uA(n, vector<int>(m, -1)), uC(n, vector<int>(m, -1));
	vector<vector<int>>dZ(n, vector<int>(m, -1)), dO(n, vector<int>(m, -1)), dA(n, vector<int>(m, -1)), dC(n, vector<int>(m, -1));
	auto check = [&](int x, int y)
		{
			if (x >= 0 && x < n && y >= 0 && y < m)
			{
				return true;
			}
			return false;
		};
	function<int(vector<vector<int>>&, int, int, int, char)> dfs = [&](vector<vector<int>>& dp, int x, int y, int p, char c)
		{
			if (dp[x][y] != -1)
			{
				return dp[x][y];
			}
			int cost = (v[x][y] == c) ? 1 : 0, res = cost;
			if (check(x + p, y))
			{
				res = max(res, dfs(dp, x + p, y, p, c) + cost);
			}
			if (check(x, y + p))
			{
				res = max(res, dfs(dp, x, y + p, p, c) + cost);
			}
			return dp[x][y] = res;
		};
	dfs(uZ, 0, 0, 1, 'Z'), dfs(uO, 0, 0, 1, 'O'), dfs(uA, 0, 0, 1, 'A'), dfs(uC, 0, 0, 1, 'C');
	dfs(dZ, n - 1, m - 1, -1, 'Z'), dfs(dO, n - 1, m - 1, -1, 'O'), dfs(dA, n - 1, m - 1, -1, 'A'), dfs(dC, n - 1, m - 1, -1, 'C');
	auto cal = [&](vector<vector<int>>& u, vector<vector<int>>& d)
		{
			int temp = u[0][0];
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					int ax = i + 1, ay = 0;
					int bx = 0, by = j + 1;
					if (check(ax, ay))
					{
						temp = max(temp, d[i][j] + u[ax][ay]);
					}
					if (check(bx, by))
					{
						temp = max(temp, d[i][j] + u[bx][by]);
					}
				}
			}
			return temp;
		};
	int Z = cal(uZ, dZ), O = cal(uO, dO), A = cal(uA, dA), C = cal(uC, dC);
	cout << Z << ' ' << O << ' ' << A << ' ' << C;
	return 0;
}