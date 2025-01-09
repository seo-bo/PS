#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int grid[101][101] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N = 0, M = 0, K = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	int result = 0;
	for (int i = 0; i < K; ++i)
	{
		int r = 0, c = 0;
		cin >> r >> c;
		r--;
		c--;
		grid[r][c] = 1;
	}
	auto get = [&](const int& x, const int& y)
		{
			int cnt = 1;
			grid[x][y] = 0;
			queue<pair<int, int>>q;
			q.push(make_pair(x, y));
			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = cur.first + direction[i][0];
					int ny = cur.second + direction[i][1];
					if (nx >= 0 && ny >= 0 && nx < N && ny < M)
					{
						if (grid[nx][ny])
						{
							grid[nx][ny] = 0;
							q.push(make_pair(nx, ny));
							cnt++;
						}
					}
				}
			}
			return cnt;
		};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (grid[i][j])
			{
				result = max(result, get(i, j));
			}
		}
	}
	cout << result;
	return 0;
}