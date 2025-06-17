#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j] - '0';
		}
	}
	queue<pii>q;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	auto bfs = [&]
		{
			int xx = 0, yy = 0;
			cin >> xx >> yy;
			vector<vector<int>>visited(n, vector<int>(m, INT_MAX));
			visited[--xx][--yy] = 0;
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
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v[nx][ny])
					{
						if (visited[nx][ny] > visited[x][y] + 1)
						{
							visited[nx][ny] = visited[x][y] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
			return visited;
		};
	vector<vector<int>>v1 = bfs();
	vector<vector<int>>v2 = bfs();
	vector<vector<int>>v3 = bfs();
	int ans1 = INT_MAX, ans2 = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ans1 = min(ans1, max({ v1[i][j],v2[i][j],v3[i][j] }));
		}
	}
	if (ans1 == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (max({ v1[i][j],v2[i][j],v3[i][j] }) == ans1)
			{
				ans2++;
			}
		}
	}
	cout << ans1 << '\n' << ans2;
	return 0;
}