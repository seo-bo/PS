#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r = 0, c = 0, wolf = 0, sheep = 0;
	cin >> r >> c;
	vector<vector<char>>v(r, vector<char>(c));
	vector<vector<bool>>visited(r, vector<bool>(c, false));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto bfs = [&](int x, int y)
		{
			int w = 0, s = 0;
			visited[x][y] = true;
			if (v[x][y] != '.')
			{
				v[x][y] == 'v' ? w++ : s++;
			}
			queue<pii>q;
			q.push(make_pair(x, y));
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (nx >= 0 && nx < r && ny >= 0 && ny < c)
					{
						if (!visited[nx][ny] && v[nx][ny] != '#')
						{
							if (v[nx][ny] != '.')
							{
								v[nx][ny] == 'v' ? w++ : s++;
							}
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
			s > w ? sheep += s : wolf += w;
		};
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (!visited[i][j] && v[i][j] != '#')
			{
				bfs(i, j);
			}
		}
	}
	cout << sheep << ' ' << wolf;
	return 0;
}