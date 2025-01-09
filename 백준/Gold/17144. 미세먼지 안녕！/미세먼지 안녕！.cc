#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> ti;
typedef tuple<int, int, int> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int r = 0, c = 0, t = 0;
	cin >> r >> c >> t;
	vector<ti>pos;
	vector<vector<int>>v(r, vector<int>(c, 0));
	vector<vector<int>>dir = { {-1,0},{0,1},{1,0},{0,-1} };
	vector<tp>dust;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (v[i][j] == -1)
			{
				int temp = 0;
				cin >> temp;
				continue;
			}
			cin >> v[i][j];
			if (v[i][j] == -1)
			{
				v[i + 1][j] = -1;
				pos.push_back(make_tuple(i, j, i + 1, j));
			}
			else if (v[i][j] > 0)
			{
				dust.push_back(make_tuple(i, j, v[i][j]));
			}
		}
	}
	assert(pos.size() == 1);
	auto solve = [&]
		{
			vector<tp>temp;
			vector<vector<int>>grid(r, vector<int>(c, 0));
			for (auto [a, b, c, d] : pos)
			{
				grid[a][b] = grid[c][d] = -1;
			}
			for (auto& [x, y, co] : dust)
			{
				int pivot = co / 5;
				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] != -1)
					{
						co -= pivot;
						grid[nx][ny] += pivot;
					}
				}
				grid[x][y] += co;
			}
			for (auto& [a, b, cc, dd] : pos)
			{
				int x = a - 1, y = b, d = 0;
				while (1)
				{
					int nx = x + dir[d][0];
					int ny = y + dir[d][1];
					if (!(nx >= 0 && nx < r && ny >= 0 && ny < c) || (d == 2 && nx == cc))
					{
						d = (d + 1) % 4;
						nx = x + dir[d][0];
						ny = y + dir[d][1];
					}
					if (grid[nx][ny] == -1)
					{
						break;
					}
					grid[x][y] = grid[nx][ny];
					x = nx;
					y = ny;
				}
				grid[a][b + 1] = 0;
				x = cc + 1, y = dd, d = 2;
				while (1)
				{
					int nx = x + dir[d][0];
					int ny = y + dir[d][1];
					if (!(nx >= 0 && nx < r && ny >= 0 && ny < c) || (d == 0 && nx == a))
					{
						d = (d + 3) % 4;
						nx = x + dir[d][0];
						ny = y + dir[d][1];
					}
					if (grid[nx][ny] == -1)
					{
						break;
					}
					grid[x][y] = grid[nx][ny];
					x = nx;
					y = ny;
				}
				grid[cc][dd + 1] = 0;
			}
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					if (grid[i][j] > 0)
					{
						temp.push_back(make_tuple(i, j, grid[i][j]));
					}
				}
			}
			v = grid;
			dust = temp;
		};
	for (int i = 0; i < t; ++i)
	{
		solve();
	}
	ll ans = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (v[i][j] == -1)
			{
				continue;
			}
			ans += v[i][j];
		}
	}
	cout << ans;
	return 0;
}