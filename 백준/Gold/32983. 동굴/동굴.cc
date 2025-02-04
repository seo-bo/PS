#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, c = 0, sx = 0, sy = 0;
	cin >> n >> m >> c >> sx >> sy;
	sx--, sy--;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<vector<int>>visited(n, vector<int>(m, INT_MAX));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	visited[sx][sy] = 0;
	queue<pii>q;
	q.push(make_pair(sx, sy));
	vector<vector<int>> dir = { {-1,0},{1,0},{0,-1},{0,1} };
	map<ll, ll>prefix;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != -1)
			{
				if (visited[nx][ny] > visited[x][y] + 1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] != -1)
			{
				prefix[visited[i][j]] += v[i][j];
			}
		}
	}
	auto it = next(prefix.begin());
	for (; it != prefix.end(); ++it)
	{
		it->second += prev(it)->second;
	}
	ll ans = 0;
	for (auto& [a, b] : prefix)
	{
		ans = max(ans, b - a * c);
	}
	cout << ans;
	return 0;
}