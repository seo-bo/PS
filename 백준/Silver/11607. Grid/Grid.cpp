#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int row = 0, col = 0;
int grid[501][501] = { 0, };
int visited[501][501] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool check = false;

void bfs()
{
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + direction[i][0] * grid[cur.first][cur.second];
			int ny = cur.second + direction[i][1] * grid[cur.first][cur.second];
			if (nx >= 0 && ny >= 0 && nx < row && ny < col)
			{
				if (!visited[nx][ny])
				{
					visited[nx][ny] = visited[cur.first][cur.second] + 1;
					if (nx == row - 1 && ny == col - 1)
					{
						check = true;
						return;
					}
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
	cin >> row >> col;
	for (int i = 0; i < row; ++i)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < col; ++j)
		{
			grid[i][j] = temp[j] - '0';
		}
	}
	bfs();
	if (check)
	{
		cout << visited[row - 1][col - 1] - 1;
	}
	else
	{
		cout << "IMPOSSIBLE";
	}

	return 0;
}