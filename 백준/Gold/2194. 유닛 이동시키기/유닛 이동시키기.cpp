#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, A = 0, B = 0, k = 0;
	cin >> n >> m >> A >> B >> k;
	vector<vector<int>>row(n + 3, vector<int>(m + 3, 0));
	vector<vector<int>>col(n + 3, vector<int>(m + 3, 0));
	vector<vector<int>>visited(n + 3, vector<int>(m + 3, INT_MAX));
	vector<vector<bool>>block(n + 3, vector<bool>(m + 3, false));
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for (int i = 0; i < k; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		block[a][b] = true;
	}
	cin >> sx >> sy >> ex >> ey;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pii>q;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			row[i][j] += row[i][j - 1] + block[i][j];
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			col[j][i] += col[j - 1][i] + block[j][i];
		}
	}
	auto check = [&](int x, int y)
		{
			vector<pii>ok = { {x,y},{x,y + B - 1},{x + A - 1,y}, {x + A - 1,y + B - 1} };
			for (auto& [a, b] : ok)
			{
				if (a >= 1 && a <= n && b >= 1 && b <= m)
				{
					continue;
				}
				return false;
			}
			vector<pii>R = { {0,1},{2,3} };
			vector<pii>C = { {0,2},{1,3} };
			for (auto& [a, b] : R)
			{
				auto [ax, ay] = ok[a];
				auto [bx, by] = ok[b];
				if (row[bx][by] - row[ax][ay - 1])
				{
					return false;
				}
			}
			for (auto& [a, b] : C)
			{
				auto [ax, ay] = ok[a];
				auto [bx, by] = ok[b];
				if (col[bx][by] - col[ax - 1][ay])
				{
					return false;
				}
			}
			return true;
		};
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (x == ex && y == ey)
		{
			cout << visited[x][y];
			return 0;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				if (visited[nx][ny] > visited[x][y] + 1 && check(nx, ny))
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << -1;
	return 0;
}