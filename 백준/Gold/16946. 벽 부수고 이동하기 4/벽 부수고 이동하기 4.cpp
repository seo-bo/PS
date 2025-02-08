#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

vector<int>check;
string grid[1001];
unordered_map<int, int>vvv;
int visited[1001][1001] = { 0, };
int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int row = 0, col = 0, k = 0;

struct point
{
	int x, y, cnt, bk;
};

void bfs(int x, int y, int order)
{
	int cnt = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	visited[x][y] = order;
	cnt++;
	while (!q.empty())
	{
		pair<int, int>cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + direction[i][0];
			int ny = cur.second + direction[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			{
				if (!visited[nx][ny] && !(grid[nx][ny] - '0'))
				{
					q.push(make_pair(nx, ny));
					visited[nx][ny] = order;
					cnt++;
				}
			}
		}
	}
	check.push_back(cnt);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int order = 1;
	cin >> row >> col;
	for (int i = 0; i < row; ++i)
	{
		cin >> grid[i];
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (!(grid[i][j] - '0') && !visited[i][j])
			{
				bfs(i, j, order++);
			}
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (!(grid[i][j] - '0'))
			{
				cout << 0;
			}
			else
			{
				ll temp = 0;
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + direction[k][0];
					int ny = j + direction[k][1];
					if (nx >= 0 && nx < row && ny >= 0 && ny < col && visited[nx][ny])
					{
						if (vvv.find(visited[nx][ny]) == vvv.end())
						{
							vvv.insert(make_pair(visited[nx][ny], 1));
							temp += check[visited[nx][ny] - 1];
						}
					}
				}
				temp = (temp + 1) % 10;
				cout << temp;
				unordered_map<int, int>().swap(vvv);
			}
		}
		cout << "\n";
	}
	return 0;
}