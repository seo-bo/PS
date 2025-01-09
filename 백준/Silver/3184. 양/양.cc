#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r = 0, c = 0, ans1 = 0, ans2 = 0;
	cin >> r >> c;
	vector<vector<char>>v(r, vector<char>(c));
	vector<vector<bool>>visited(r, vector<bool>(c));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < r; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < c; ++j)
		{
			v[i][j] = str[j];
		}
	}
	auto bfs = [&](int x, int y)
		{
			int sheep = 0;
			int wolf = 0;
			if (v[x][y] == 'o')
			{
				sheep++;
			}
			else if (v[x][y] == 'v')
			{
				wolf++;
			}
			queue<pii>q;
			visited[x][y] = true;
			q.push(make_pair(x, y));
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && v[nx][ny] != '#')
					{
						if (v[nx][ny] == 'o')
						{
							sheep++;
						}
						else if (v[nx][ny] == 'v')
						{
							wolf++;
						}
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
			if (sheep > wolf)
			{
				ans1 += sheep;
			}
			else
			{
				ans2 += wolf;
			}
		};
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (!visited[i][j] && v[i][j] != '#')
			{
				bfs(i,j);
			}
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}