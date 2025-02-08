#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;
int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int visited[1010][1001][2] = { 0, };
int result[1010][1010] = { 0, };
vector<string>maze;
int row = 0, col = 0, Min = INF;

typedef struct Pos
{
	int x;
	int y;
	int crash;
}Pos;

void bfs()
{
	queue<Pos>Q;
	visited[0][0][0] = 1;
	result[0][0] = 1;
	Q.push({ 0,0,0 });
	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int crash = Q.front().crash;
		if (x == row - 1 && y == col - 1)
		{
			Min = min(Min, result[x][y]);
		}
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (maze[nx][ny] == '0' && !visited[nx][ny][crash])
				{
					visited[nx][ny][crash] = 1;
					result[nx][ny] = result[x][y] + 1;
					Q.push({ nx,ny,crash });
				}
				else if (maze[nx][ny] == '1' && crash == 0 && !visited[nx][ny][1])
				{
					visited[nx][ny][1] = 1;
					result[nx][ny] = result[x][y] + 1;
					Q.push({ nx,ny,1 });
				}
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> col;
	maze.resize(row);
	for (int i = 0; i < row; i++)
	{
		cin >> maze[i];
		for (int j = 0; j < col; j++)
		{
			result[i][j] = INF;
		}
	}
	bfs();
	if (result[row - 1][col - 1] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << Min;
	}
	return 0;
}
