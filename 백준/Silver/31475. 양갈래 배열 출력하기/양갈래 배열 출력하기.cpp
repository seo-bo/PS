#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	char cc;
	cin >> n >> m >> cc;
	vector<vector<int>>ans(n, vector<int>(m));
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	vector<vector<int>>dir;
	int sx = 0, sy = 0;
	if (cc == 'U')
	{
		vector<vector<int>>temp = { {1,0},{0,-1},{-1,0},{0,1} };
		dir = move(temp);
		sx = 0, sy = m / 2;
	}
	else if (cc == 'D')
	{
		vector<vector<int>>temp = { {-1,0},{0,-1},{1,0},{0,1} };
		dir = move(temp);
		sx = n - 1, sy = m / 2;
	}
	else if (cc == 'L')
	{
		vector<vector<int>>temp = { {0,1},{-1,0},{0,-1},{1,0} };
		dir = move(temp);
		sx = n / 2, sy = 0;
	}
	else
	{
		vector<vector<int>>temp = { {0,-1},{-1,0},{0,1},{1,0} };
		dir = move(temp);
		sx = n / 2, sy = m - 1;
	}
	auto check = [&](int x, int y, int d)
		{
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
			{
				return true;
			}
			return false;
		};
	int num = 1;
	while (check(sx, sy, 0))
	{
		visited[sx][sy] = true;
		ans[sx][sy] = num++;
		sx = sx + dir[0][0];
		sy = sy + dir[0][1];
	}
	ans[sx][sy] = num;
	function<void(int, int, int, int, int)> dfs = [&](int x, int y, int d, int pl, int ber)
		{
			visited[x][y] = true;
			ans[x][y] = ber;
			if (!check(x, y, d))
			{
				d = (d + pl + 4) % 4;
				if (!check(x, y, d))
				{
					return;
				}
			}
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			dfs(nx, ny, d, pl, ber + 1);
		};
	dfs(sx, sy, 1, 1, num);
	dfs(sx, sy, 3, -1, num);
	for (auto& i : ans)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}