#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<int>>v(h, vector<int>(w, 0));
	vector<vector<bool>>visited(h, vector<bool>(w, false));
	vector<ti>temp;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] != -1)
			{
				temp.push_back(make_tuple(v[i][j], i, j));
			}
			else
			{
				visited[i][j] = true;
			}
		}
	}
	sort(temp.begin(), temp.end(), [&](const ti& a, const ti& b)
		{
			return get<0>(a) > get<0>(b);
		});
	auto bfs = [&](int x, int y)
		{
			vector<pii>pos;
			queue<pii>q;
			pos.push_back(make_pair(x, y));
			visited[x][y] = true;
			q.push(make_pair(x, y));
			while (!q.empty())
			{
				auto [xx, yy] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = xx + dir[i][0];
					int ny = yy + dir[i][1];
					if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && v[nx][ny] != -1 && v[nx][ny] != v[xx][yy] && v[nx][ny] <= v[xx][yy])
					{
						if (v[nx][ny] == v[xx][yy] - 1)
						{
							visited[nx][ny] = true;
							pos.push_back(make_pair(nx, ny));
							q.push(make_pair(nx, ny));
						}
						else
						{
							for (auto& [a, b] : pos)
							{
								visited[a][b] = false;
							}
							return false;
						}
					}
				}
			}
			return true;
		};
	int ans = 0;
	for (auto& [c, x, y] : temp)
	{
		if (!visited[x][y])
		{
			if (c == 0)
			{
				visited[x][y] = true;
			}
			else if (bfs(x, y))
			{
				ans++;
			}
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (!visited[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}