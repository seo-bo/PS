#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int>ti;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, f = 0;
	cin >> n >> m >> f;
	vector<ti>pos(m + 1);
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
			if (v[i][j])
			{
				v[i][j] = -1;
			}
		}
	}
	int x = 0, y = 0, ver = 0;
	cin >> x >> y;
	pos[0] = make_tuple(x, y, x, y);
	for (int i = 1; i <= m; ++i)
	{
		auto& [a, b, c, d] = pos[i];
		cin >> a >> b >> c >> d;
		if (a == x && b == y)
		{
			ver = i;
		}
		v[a][b] = i;
	}
	vector<bool>flag(m + 1, false);
	auto bfs = [&](ti s) -> pair<ti, ll>
		{
			ti pp = make_tuple(INT_MAX, INT_MAX, INT_MAX, -1);
			auto& [a, b, c, d] = s;
			vector<vector<int>>visited(n + 1, vector<int>(n + 1, INT_MAX));
			queue<tp>q;
			q.push(make_tuple(c, d, 0));
			visited[c][d] = 0;
			auto check = [&](int xx, int yy)
				{
					if (v[xx][yy] && !flag[v[xx][yy]])
					{
						if (get<2>(pp) > visited[xx][yy])
						{
							pp = make_tuple(xx, yy, visited[xx][yy], v[xx][yy]);
						}
						else if (get<2>(pp) == visited[xx][yy])
						{
							if (get<0>(pp) == xx)
							{
								if (get<1>(pp) > yy)
								{
									pp = make_tuple(xx, yy, visited[xx][yy], v[xx][yy]);
								}
							}
							else if (get<0>(pp) > xx)
							{
								pp = make_tuple(xx, yy, visited[xx][yy], v[xx][yy]);
							}
						}
					}
				};
			check(c, d);
			while (!q.empty())
			{
				auto [sx, sy, cost] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = sx + dir[i][0];
					int ny = sy + dir[i][1];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && visited[nx][ny] > cost + 1 && v[nx][ny] != -1)
					{
						visited[nx][ny] = cost + 1;
						q.push(make_tuple(nx, ny, visited[nx][ny]));
						check(nx, ny);
					}
				}
			}
			return make_pair(pp, visited[a][b]);
		};
	auto fail = [&]
		{
			cout << -1;
			exit(0);
		};
	while (1)
	{
		pair<ti, ll>p = bfs(pos[ver]); // 행, 열, 이동거리, 번호
		auto& [a, b, c, d] = p.first;
		if (f - p.second < 0)
		{
			fail();
		}
		f += p.second;
		if (c == INT_MAX)
		{
			break;
		}
		if (f - c <= 0)
		{
			fail();
		}
		f -= c;
		flag[ver] = true;
		ver = d;
	}
	for (int i = 1; i <= m; ++i)
	{
		if (!flag[i])
		{
			fail();
		}
	}
	cout << f;
	return 0;
}