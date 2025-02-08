#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int row = 0, col = 0;
string grid[20];
bool visited[20][20];
int house = 0;
int result = INT_MAX;
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct point
{
	int x;
	int y;
};

int bfs(point x, point y)
{
	int temp = house;
	int time = 0;
	queue<pair<point, int>>q;
	q.push(make_pair(x, 0)); q.push(make_pair(y, 0));
	visited[x.x][x.y] = visited[y.x][y.y] = true;
	while (!q.empty() && temp > 0)
	{
		if (time > result)
		{
			return time;
		}
		pair<point, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first.x + direction[i][0];
			int ny = cur.first.y + direction[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (!visited[nx][ny])
				{
					point po = { nx, ny };
					if (grid[nx][ny] == '1')
					{
						temp--;
						time = max(time, cur.second + 1);
					}
					visited[nx][ny] = true;
					q.push(make_pair(po, cur.second + 1));
				}
			}
		}
	}
	return time;
}

void dfs(int depth = 0, point x = { 0,0 }, point y = { 0,0 })
{
	if (depth == 2)
	{
		memset(visited, false, sizeof(visited));
		int time = bfs(x, y);
		result = min(result, time);
		return;
	}
	for (int i = y.x; i < row; ++i)
	{
		for (int j = y.y; j < col; ++j)
		{
			if (grid[i][j] == '0')
			{
				dfs(depth + 1, y, { i,j });
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
		cin >> grid[i];
		for (int j = 0; j < col; ++j)
		{
			if (grid[i][j] == '1')
			{
				house++;
			}
		}
	}
	dfs();
	cout << result;
	return 0;
}