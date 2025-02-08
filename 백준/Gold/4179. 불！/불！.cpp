#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

vector<string>maze;
queue<pair<int, int>>fire;
queue<pair<int, int>>human;
int visited[1001][1001] = { 0, };
int firetime[1001][1001] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int row = 0, col = 0;

void spreadfire()
{
	while (!fire.empty())
	{
		int x = fire.front().first;
		int y = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (maze[nx][ny] == '.' && firetime[nx][ny] == INF)
				{
					firetime[nx][ny] = firetime[x][y] + 1;
					fire.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int escape()
{
	while (!human.empty())
	{
		int x = human.front().first;
		int y = human.front().second;
		human.pop();
		if (x == 0 || x == row - 1 || y == 0 || y == col - 1) 
		{
			return visited[x][y] + 1;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (maze[nx][ny] == '.' && visited[nx][ny] == 0 && (visited[x][y] + 1 < firetime[nx][ny] || firetime[nx][ny] == INF))
				{
					visited[nx][ny] = visited[x][y] + 1;
					human.push(make_pair(nx, ny));
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> col;
	maze.resize(row);
	for (int i = 0; i < row; ++i)
	{
		cin >> maze[i];
		for (int j = 0; j < col; ++j)
		{
			firetime[i][j] = INF;
			if (maze[i][j] == 'J')
			{
				human.push(make_pair(i, j));
				visited[i][j] = 0;
			}
			else if (maze[i][j] == 'F')
			{
				fire.push(make_pair(i, j));
				firetime[i][j] = 0;
			}
		}
	}
	spreadfire();
	int result = escape();
	if (result == -1)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << result;
	}
	
	return 0;
}
