#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	unordered_map<char, int>mm = { {'L',2},{'U',0},{'D',1},{'R',3} };
	for (auto& i : v)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			i[j] = str[j];
		}
	}
	int cnt = 1;
	vector<vector<int>>ok(n, vector<int>(m));
	{
		vector<vector<bool>>visited(n, vector<bool>(m, false));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (!visited[i][j])
				{
					queue<pii>q;
					q.push(make_pair(i, j));
					visited[i][j] = true;
					while (!q.empty())
					{
						auto [xx, yy] = q.front();
						q.pop();
						ok[xx][yy] = cnt;
						for (int k = 0; k < 4; ++k)
						{
							int nx = xx + dir[k][0];
							int ny = yy + dir[k][1];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && v[nx][ny] == v[xx][yy])
							{
								visited[nx][ny] = true;
								ok[nx][ny] = cnt;
								q.push(make_pair(nx, ny));
							}
						}
					}
					cnt++;
				}
			}
		}
	}
	int sx = 0, sy = 0;
	cin >> sx >> sy;
	sx--;
	sy--;
	string _;
	cin >> _;
	set<int>ss;
	for (auto& i : _)
	{
		if (i == 'W')
		{
			ss.insert(ok[sx][sy]);
			continue;
		}
		sx = sx + dir[mm[i]][0];
		sy = sy + dir[mm[i]][1];
	}
	vector<vector<bool>>visited(n, vector<bool>(m, false));
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
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && ok[nx][ny] == ok[x][y])
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (ss.find(ok[i][j]) != ss.end())
			{
				ss.erase(ok[i][j]);
				bfs(i, j);
			}
		}
	}
	visited[sx][sy] = true;
	for (int i = 0; i < 4; ++i)
	{
		int nx = sx + dir[i][0];
		int ny = sy + dir[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			visited[nx][ny] = true;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (visited[i][j])
			{
				cout << '.';
			}
			else
			{
				cout << '#';
			}
		}
		cout << '\n';
	}
	return 0;
}