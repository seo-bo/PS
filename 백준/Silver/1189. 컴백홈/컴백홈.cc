#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double lb;

vector<ll>v(21);
int R = 0, C = 0, K = 0;
bool visited[5][5] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
char grid[5][5];
ll result = 0;

void dfs(int depth = 1, int x = R - 1, int y = 0)
{
	if (depth == K)
	{
		if (x == 0 && y == C - 1)
		{
			result++;
		}
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C)
		{
			if (grid[nx][ny] != 'T' && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				dfs(depth + 1, nx, ny);
				visited[nx][ny] = false;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> K;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> grid[i][j];
		}
	}
	visited[R - 1][0] = true;
	dfs();
	cout << result;
	return 0;
}