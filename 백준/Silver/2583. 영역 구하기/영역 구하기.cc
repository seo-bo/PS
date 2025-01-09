#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m = 0, n = 0, k = 0;
	cin >> m >> n >> k;
	vector<vector<int>>grid(m, vector<int>(n, 0));
	vector<vector<bool>>visited(m, vector<bool>(n, false));
	for (int i = 0; i < k; ++i)
	{
		int sx = 0, sy = 0, ex = 0, ey = 0;
		cin >> sx >> sy >> ex >> ey;
		for (int i = sy; i < ey; ++i)
		{
			for (int j = sx; j < ex; ++j)
			{
				grid[i][j] = 1;
			}
		}
	}
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	auto bfs = [&](int x, int y)
		{
			int cnt = 1;
			queue<pii>q;
			q.push(make_pair(x, y));
			visited[x][y] = true;
			while (!q.empty())
			{
				pii cur = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = cur.first + dir[i][0];
					int ny = cur.second + dir[i][1];
					if (nx >= 0 && ny >= 0 && nx < m && ny < n)
					{
						if (!visited[nx][ny] && !grid[nx][ny])
						{
							cnt++;
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
			return cnt;
		};
	int ans = 0;
	vector<int>a;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j] && !grid[i][j])
			{
				ans++;
				a.push_back(bfs(i, j));
			}
		}
	}
	cout << ans << '\n';
	sort(a.begin(), a.end());
	for (auto& i : a)
	{
		cout << i << ' ';
	}
	return 0;
}