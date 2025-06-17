#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> m >> n;
	int sx = 0, sy = 0, ex = 0, ey = 0, pivot = 0;
	vector<vector<char>>v(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
			if (str[j] == 'S')
			{
				sx = i, sy = j;
			}
			if (str[j] == 'E')
			{
				ex = i, ey = j;
			}
			if (str[j] == 'X')
			{
				v[i][j] = (pivot++ + '0');
			}
		}
	}
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<tp>q;
	q.push(make_tuple(sx, sy, 0));
	vector<vector<vector<int>>>visited(n, vector<vector<int>>(m, vector<int>((1 << pivot), INT_MAX)));
	visited[sx][sy][0] = 0;
	while (!q.empty())
	{
		auto [x, y, co] = q.front();
		if (x == ex && y == ey && co == (1 << pivot) - 1)
		{
			cout << visited[x][y][co];
			break;
		}
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#')
			{
				int nc = co;
				if ('0' <= v[nx][ny] && v[nx][ny] <= '9')
				{
					nc |= (1 << (v[nx][ny] - '0'));
				}
				if (visited[nx][ny][nc] > visited[x][y][co] + 1)
				{
					visited[nx][ny][nc] = visited[x][y][co] + 1;
					q.push(make_tuple(nx, ny, nc));
				}
			}
		}
	}
	return 0;
}