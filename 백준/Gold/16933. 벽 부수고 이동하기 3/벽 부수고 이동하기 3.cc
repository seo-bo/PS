#include <bits/stdc++.h>
using namespace std;

string grid[1001];
int row = 0, col = 0, k = 0;
int visited[1001][1001][11] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct wall
{
	int x;
	int y;
	int daytime;
	int cnt;
	int bk;
};


void bfs() // 0 = 낮, 1 = 밤
{
	queue<wall>q;
	q.push({ 0,0,0,1,0 });
	visited[0][0][0] = 1;
	while (!q.empty())
	{
		wall cur = q.front();
		q.pop();
		if (cur.x == row - 1 && cur.y == col - 1)
		{
			cout << cur.cnt;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + direction[i][0];
			int ny = cur.y + direction[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (!(grid[nx][ny] - '0')) // 만약 0이고
				{
					if (!visited[nx][ny][cur.bk]) 
					{
						visited[nx][ny][cur.bk] = 1;
						q.push({ nx,ny,(cur.daytime + 1) % 2, cur.cnt + 1, cur.bk });
					}
				}
				else if (grid[nx][ny] - '0') // 만약 1이고
				{
					if (cur.bk < k)
					{
						if (!visited[nx][ny][cur.bk + 1])
						{
							if (!cur.daytime) // 낮이면
							{
								visited[nx][ny][cur.bk + 1] = 1;
								q.push({ nx,ny,(cur.daytime + 1) % 2, cur.cnt + 1,cur.bk + 1 });
							}
							else // 밤이면
							{
								q.push({ cur.x,cur.y,(cur.daytime + 1) % 2,cur.cnt + 1,cur.bk });
							}
						}
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
	cin >> row >> col >> k;
	for (int i = 0; i < row; ++i)
	{
		cin >> grid[i];
	}
	bfs();
	return 0;
}