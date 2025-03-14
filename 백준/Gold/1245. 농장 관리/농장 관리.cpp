#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int ans = 0;
	vector<vector<int>> dir = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1} };
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	auto bfs = [&](int sx, int sy)
		{
			vector<pii>temp;
			visited[sx][sy] = true;
			queue<pii>q;
			q.push(make_pair(sx, sy));
			while (!q.empty())
			{
				auto [x, y] = q.front();
				q.pop();
				temp.push_back(make_pair(x, y));
				for (int i = 0; i < 8; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && v[x][y] == v[nx][ny])
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
			for (auto& [x, y] : temp)
			{
				for (int i = 0; i < 8; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] > v[x][y])
					{
						return false;
					}
				}
			}
			return true;
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] && !visited[i][j])
			{
				if (bfs(i, j))
				{
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}