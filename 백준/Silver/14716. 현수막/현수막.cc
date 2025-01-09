#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int direction[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
int row = 0, col = 0, result = 0;
int grid[251][251] = { 0, };
bool visited[251][251] = { 0, };

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
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (!visited[nx][ny] && grid[nx][ny] == 1)
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
	cin >> row >> col;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (grid[i][j] == 1 && !visited[i][j])
			{
				bfs(i, j);
				result++;
			}
		}
	}
	cout << result;
	return 0;
}