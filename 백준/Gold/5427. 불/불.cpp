#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> m >> n;
		vector<vector<char>>v(n, vector<char>(m));
		vector<vector<int>>fire(n, vector<int>(m, INT_MAX)), dir = { {-1,0},{1,0},{0,-1},{0,1} };
		vector<vector<bool>>visited(n, vector<bool>(m, false));
		queue<pii>qq;
		pii s = make_pair(-1, -1);
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; ++j)
			{
				v[i][j] = str[j];
				if (v[i][j] == '*')
				{
					qq.push(make_pair(i, j));
					fire[i][j] = 0;
				}
				else if (v[i][j] == '@')
				{
					s = make_pair(i, j);
				}
			}
		}
		while (!qq.empty())
		{
			auto [x, y] = qq.front();
			qq.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (fire[nx][ny] > fire[x][y] + 1 && v[nx][ny] == '.')
					{
						fire[nx][ny] = fire[x][y] + 1;
						qq.push(make_pair(nx, ny));
					}
				}
			}
		}
		queue<tuple<int, int, int>>q;
		auto [a, b] = s;
		q.push(make_tuple(0, a, b));
		visited[a][b] = true;
		auto bfs = [&]
			{
				while (!q.empty())
				{
					auto [_, x, y] = q.front();
					q.pop();
					for (int i = 0; i < 4; ++i)
					{
						int nx = x + dir[i][0];
						int ny = y + dir[i][1];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m)
						{
							if (!visited[nx][ny] && v[nx][ny] == '.' && fire[nx][ny] > _ + 1)
							{
								visited[nx][ny] = true;
								q.push(make_tuple(_ + 1, nx, ny));
							}
						}
						else
						{
							cout << _ + 1 << '\n';
							return;
						}
					}
				}
				cout << "IMPOSSIBLE" << '\n';
			};
		bfs();
	}
	return 0;
}