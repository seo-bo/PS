#include <bits/stdc++.h>
#include <unordered_set>
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
		vector<vector<char>>v(n, vector<char>(m));
		vector<vector<int>>per(n, vector<int>(m, 0));
		vector<vector<bool>>visited(n, vector<bool>(m, false));
		vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
		pii st, ed;
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; ++j)
			{
				v[i][j] = str[j];
				if (str[j] == 'S')
				{
					v[i][j] = '.';
					st = make_pair(i, j);
				}
				else if (str[j] == 'E')
				{
					v[i][j] = '.';
					ed = make_pair(i, j);
				}
			}
		}
		int cnt = 0;
		auto bfs = [&](int x, int y)
			{
				queue<pii>q;
				q.push(make_pair(x, y));
				visited[x][y] = true;
				per[x][y] = cnt;
				while (!q.empty())
				{
					auto [xx, yy] = q.front();
					q.pop();
					for (int i = 0; i < 4; ++i)
					{
						int nx = xx + dir[i][0];
						int ny = yy + dir[i][1];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && v[nx][ny] != '#')
						{
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
							per[nx][ny] = cnt;
						}
					}
				}
			};
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (!visited[i][j] && v[i][j] != '#')
				{
					cnt++;
					bfs(i, j);
				}
			}
		}
		if (per[st.first][st.second] == per[ed.first][ed.second])
		{
			cout << "YES" << '\n';
			continue;
		}
		unordered_map<int, unordered_set<int>>graph;
		for (int i = 0; i < n; ++i)
		{
			int siz = 0, temp = 0;
			for (int j = 0; j < m; ++j)
			{
				if (v[i][j] == '.')
				{
					temp = per[i][j];
					siz++;
				}
				else
				{
					for (int k = siz - 1; k >= 1; --k)
					{
						int nx = i;
						int ny = j + k;
						if (ny >= 0 && ny < m && v[nx][ny] != '#' && per[nx][ny] != temp)
						{
							graph[temp].insert(per[nx][ny]);
						}
					}
					siz = 0;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			int siz = 0, temp = 0;
			for (int j = m - 1; j >= 0; --j)
			{
				if (v[i][j] == '.')
				{
					temp = per[i][j];
					siz++;
				}
				else
				{
					for (int k = siz - 1; k >= 1; --k)
					{
						int nx = i;
						int ny = j - k;
						if (ny >= 0 && ny < m && v[nx][ny] != '#' && per[nx][ny] != temp)
						{
							graph[temp].insert(per[nx][ny]);
						}
					}
					siz = 0;
				}
			}
		}
		for (int j = 0; j < m; ++j)
		{
			int siz = 0, temp = 0;
			for (int i = 0; i < n; ++i)
			{
				if (v[i][j] == '.')
				{
					temp = per[i][j];
					siz++;
				}
				else
				{
					for (int k = siz - 1; k >= 1; --k)
					{
						int nx = i + k;
						int ny = j;
						if (nx >= 0 && nx < n && v[nx][ny] != '#' && per[nx][ny] != temp)
						{
							graph[temp].insert(per[nx][ny]);
						}
					}
					siz = 0;
				}
			}
		}
		for (int j = 0; j < m; ++j)
		{
			int siz = 0, temp = 0;
			for (int i = n - 1; i >= 0; --i)
			{
				if (v[i][j] == '.')
				{
					temp = per[i][j];
					siz++;
				}
				else
				{
					for (int k = siz - 1; k >= 1; --k)
					{
						int nx = i - k;
						int ny = j;
						if (nx >= 0 && nx < n && v[nx][ny] != '#' && per[nx][ny] != temp)
						{
							graph[temp].insert(per[nx][ny]);
						}
					}
					siz = 0;
				}
			}
		}
		auto sv = [&]()
			{
				vector<bool>vis(cnt + 1);
				queue<int>q;
				q.push(per[st.first][st.second]);
				vis[q.front()] = true;
				while (!q.empty())
				{
					int a = q.front();
					q.pop();
					if (a == per[ed.first][ed.second])
					{
						cout << "YES" << '\n';
						return;
					}
					for (auto& i : graph[a])
					{
						if (!vis[i])
						{
							vis[i] = true;
							q.push(i);
						}
					}
				}
				cout << "NO" << '\n';
			};
		sv();
	}
	return 0;
}