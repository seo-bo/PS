#include <bits/stdc++.h>
using namespace std;

string grid[1001];
bool visited[1001][1001][10] = {false,};
int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int row = 0, col = 0, k = 0;

struct point
{
	int x, y, cnt, bk;
};

void bfs()
{
	queue<point>q;
	q.push({ 0,0,1,0 });
	visited[0][0][0] = true;
	while (!q.empty())
	{
		point cur = q.front();
		if (cur.x == row - 1 && cur.y == col - 1)
		{
			cout << cur.cnt;
			return;
		}
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.x + direction[i][0];
			int ny = cur.y + direction[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (!visited[nx][ny][cur.bk])
				{
					if (!(grid[nx][ny] - '0'))
					{
						visited[nx][ny][cur.bk] = true;
						q.push({ nx,ny,cur.cnt + 1,cur.bk });
					}
					else
					{
						if (cur.bk < k)
						{
							visited[nx][ny][cur.bk] = true;
							q.push({ nx,ny,cur.cnt + 1,cur.bk + 1 });
						}
					}
				}
			}
		}
	}
	cout << -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> col >> k;
	for (int i = 0; i < row; ++i)
	{
		cin >> grid[i];
	}
	bfs();
	return 0;
}