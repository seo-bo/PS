#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>>v(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; ++j)
			{
				v[i][j] = (str[j] == '#');
			}
		}
		vector<vector<bool>>visited(n, vector<bool>(m, false));
		vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
		auto bfs = [&](int xx, int yy)
			{
				visited[xx][yy] = true;
				queue<pii>q;
				q.push(make_pair(xx, yy));
				while (!q.empty())
				{
					auto [x, y] = q.front();
					q.pop();
					for (int i = 0; i < 4; ++i)
					{
						int nx = x + dir[i][0];
						int ny = y + dir[i][1];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && v[nx][ny])
						{
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			};
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (v[i][j] && !visited[i][j])
				{
					ans++;
					bfs(i, j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}