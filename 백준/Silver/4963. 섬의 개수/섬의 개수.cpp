#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int w = 0, h = 0;
int grid[51][51] = { 0, };
bool visited[51][51] = { false, };
int direction[8][2] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1} };

void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	visited[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nx = cur.first + direction[i][0];
			int ny = cur.second + direction[i][1];
			if (nx >= 0 && nx < w && ny >= 0 && ny < h)
			{
				if (!visited[nx][ny] && grid[nx][ny])
				{
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1)
	{
		int result = 0;
		cin >> h >> w;
		if (!w && !h)
		{
			break;
		}
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				cin >> grid[i][j];
			}
		}
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
			{
				if (grid[i][j] && !visited[i][j])
				{
					bfs(i, j);
					result++;
				}
			}
		}
		cout << result << "\n";
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
