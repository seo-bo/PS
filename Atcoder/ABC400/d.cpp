#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
		}
	}
	deque<tp>dq;
	int sx = 0, sy = 0, ex = 0, ey = 0;
	cin >> sx >> sy >> ex >> ey;
	sx--;
	sy--;
	ex--;
	ey--;
	vector<vector<vector<vector<int>>>>visited(n, vector<vector<vector<int>>>(m, vector<vector<int>>(5, vector<int>(3, INT_MAX))));
	visited[sx][sy][0][0] = 0;
	dq.push_back(make_tuple(sx, sy, 0, 0));
	vector<vector<int>>dir = { {0,0}, { -1,0 },{1,0},{0,-1},{0,1} };
	while (!dq.empty())
	{
		auto [x, y, d, cnt] = dq.front();
		dq.pop_front();
		if (x == ex && y == ey)
		{
			cout << visited[x][y][d][cnt];
			return 0;
		}
		for (int i = 1; i <= 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (v[nx][ny] == '.')
				{
					int cost = max(0, cnt - 1);
					if (visited[nx][ny][d][cost] > visited[x][y][d][cnt])
					{
						visited[nx][ny][d][cost] = visited[x][y][d][cnt];
						dq.push_front(make_tuple(nx, ny, d, cost));
					}
				}
				else
				{
					if (cnt == 1 && d == i)
					{
						int cost = max(0, cnt - 1);
						if (visited[nx][ny][d][cost] > visited[x][y][d][cnt])
						{
							visited[nx][ny][d][cost] = visited[x][y][d][cnt];
							dq.push_front(make_tuple(nx, ny, d, cost));
						}
					}
					else
					{
						if (visited[nx][ny][i][1] > visited[x][y][d][cnt] + 1)
						{
							visited[nx][ny][i][1] = visited[x][y][d][cnt] + 1;
							dq.push_back(make_tuple(nx, ny, i, 1));
						}
					}
				}
			}
		}
	}
	return 0;
}
