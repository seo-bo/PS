#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int visited[16][16] = { 0, };
char grid[16][16];
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
pair<int, int>point, goal;
int row = 0, col = 0;

void bfs()
{
	queue<pair<int, int>>q;
	visited[point.first][point.second] = 1;
	q.push(make_pair(point.first, point.second));
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		if (grid[cur.first][cur.second] == 'G')
		{
			cout << "Shortest Path: " << visited[cur.first][cur.second] - 1 << "\n";
			return;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + direction[i][0];
			int ny = cur.second + direction[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (!visited[nx][ny] && grid[nx][ny] != 'X')
				{
					visited[nx][ny] = visited[cur.first][cur.second] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << "No Exit" << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		cin >> row >> col;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cin >> grid[i][j];
				if (grid[i][j] == 'S')
				{
					point = make_pair(i, j);
				}
			}
		}
		bfs();
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}