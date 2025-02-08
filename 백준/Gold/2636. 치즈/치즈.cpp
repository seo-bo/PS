#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

ll result = 0, cnt = 0;
int grid[101][101] = { 0, };
bool visited[101][101] = { false, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
queue<pair<int, int>>q;
queue<pair<int, int>>cheese;
int row = 0, col = 0;

void bfs()
{
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + direction[i][0];
			int ny = cur.second + direction[i][1];
			if (nx >= 0 && ny >= 0 && nx < row && ny < col)
			{
				if (!visited[nx][ny])
				{
					if (!grid[nx][ny]) // 공기라면
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
					else // 치즈라면
					{
						visited[nx][ny] = true;
						cheese.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

bool check()
{
	if (cheese.empty())
	{
		return false;
	}
	result = cheese.size();
	queue<pair<int, int>>().swap(q);
	cnt++;
	while (!cheese.empty())
	{
		grid[cheese.front().first][cheese.front().second] = 0;
		q.push(cheese.front());
		cheese.pop();
	}
	return true;
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
	q.push(make_pair(0, 0));
	while (1)
	{
		bfs();
		if (!check())
		{
			cout << cnt << "\n" << result;
			break;
		}
	}
	return 0;
}