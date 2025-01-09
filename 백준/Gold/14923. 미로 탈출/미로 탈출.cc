#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int grid[1001][1001];
int visited[1005][1005][2] = { 0, };
int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int row = 0, col = 0, start_x = 0, start_y = 0, end_x = 0, end_y = 0;

struct maze
{
	int x, y, cnt, crash;
};

void bfs()
{
	queue<maze>q;
	q.push({start_x,start_y,0,0});
	visited[start_x][start_y][0] = 1;
	while (!q.empty())
	{
		maze cur = q.front();
		if (cur.x == end_x && cur.y == end_y)
		{
			cout << cur.cnt;
			return;
		}
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.x + direction[i][0];
			int ny = cur.y + direction[i][1];
			if (nx >= 1 && nx <= row && ny >= 1 && ny <= col)
			{
				if (!visited[nx][ny][cur.crash])
				{
					if (grid[nx][ny] && !cur.crash)
					{
						visited[nx][ny][1] = 1;
						q.push({ nx,ny,cur.cnt + 1,1 });
					}
					else if (!grid[nx][ny])
					{
						visited[nx][ny][cur.crash] = 1;
						q.push({ nx,ny,cur.cnt + 1,cur.crash });
					}
				}
			}
		}
	}
	cout << -1;
	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> col >> start_x >> start_y >> end_x >> end_y;
	for (int i = 1; i <= row; ++i)
	{
		for (int j = 1; j <= col; ++j)
		{
			cin >> grid[i][j];
		}
	}
	bfs();
	return 0;
}