#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

int mapp[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int row = 0, col = 0;
int startr = 0, startc = 0;
void bfs()
{
	queue<pair<int, int>>q;
	visited[startr][startc] = 1;
	q.push(make_pair(startr, startc));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (!visited[nx][ny] && mapp[nx][ny] != 0)
			{
				if (nx >= 0 && nx < row && ny >= 0 && ny < col)
				{
					visited[nx][ny] = 1;
					mapp[nx][ny] = mapp[x][y] + 1;
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
			cin >> mapp[i][j];
			if (mapp[i][j] == 2)
			{
				startr = i;
				startc = j;
				mapp[i][j] = 0;
			}
			else if (mapp[i][j] == 0)
			{
				mapp[i][j] = 0;
			}
			else
			{
				mapp[i][j] = INF;
			}
		}
	}
	bfs();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (mapp[i][j] == INF)
			{
				cout << -1 << " ";
			}
			else
			{
				cout << mapp[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
