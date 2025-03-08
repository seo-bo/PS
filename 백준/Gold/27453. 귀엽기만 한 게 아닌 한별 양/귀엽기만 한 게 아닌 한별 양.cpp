#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int, int>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	int sx = 0, sy = 0, ex = 0, ey = 0;
	vector<vector<int>>v(n, vector<int>(m));
	unordered_map<int, int>mm = { {0,0}, { 1,2 },{2,1},{3,4},{4,3} };
	vector<vector<vector<int>>>visited(n, vector<vector<int>>(m, vector<int>(5, INT_MAX)));
	vector<vector<int>>dir = { {0,0}, { -1,0 },{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = 0;
			if (str[j] == 'S')
			{
				sx = i, sy = j;
			}
			else if (str[j] == 'H')
			{
				ex = i, ey = j;
			}
			else if (str[j] == 'X')
			{
				v[i][j] = 100;
			}
			else
			{
				v[i][j] = str[j] - '0';
			}
		}
	}
	visited[sx][sy][0] = 0;
	queue<tp>q;
	q.push(make_tuple(sx, sy, 0, 0, 0));
	while (!q.empty())
	{
		auto [x, y, d, a, b] = q.front();
		q.pop();
		if (x == ex && y == ey)
		{
			cout << visited[x][y][d];
			return 0;
		}
		for (int i = 1; i <= 4; ++i)
		{
			if (mm[d] == i)
			{
				continue;
			}
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				int cost = a + b + v[nx][ny];
				if (cost > k)
				{
					continue;
				}
				if (visited[nx][ny][i] > visited[x][y][d] + 1)
				{
					visited[nx][ny][i] = visited[x][y][d] + 1;
					q.push(make_tuple(nx, ny, i, b, v[nx][ny]));
				}
			}
		}
	}
	cout << -1;
	return 0;
}