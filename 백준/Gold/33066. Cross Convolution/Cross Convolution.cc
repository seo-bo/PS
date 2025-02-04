#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0, s = 0;
	cin >> n >> m >> k >> s;
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	k /= 2;
	vector<vector<ll>>col(n + 1, vector<ll>(m + 1, 0));
	vector<vector<ll>>row(n + 1, vector<ll>(m + 1, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	auto check = [&](int x, int y)
		{
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0] * k;
				int ny = y + dir[i][1] * k;
				if (!(nx >= 1 && nx <= n && ny >= 1 && ny <= m))
				{
					return false;
				}
			}
			return true;
		};
	int sx = 0, sy = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			col[i][j] = col[i][j - 1] + v[i][j];
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			row[j][i] = row[j - 1][i] + v[j][i];
		}
	}
	auto _ = [&]
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= m; ++j)
				{
					if (check(i, j))
					{
						sx = i, sy = j;
						return;
					}
				}
			}
		};
	_();
	vector<vector<ll>>ans;
	while (check(sx, sy))
	{
		int x = sx, y = sy;
		vector<ll>tt;
		while (check(x, y))
		{
			ll sum = row[x + k][y] - row[x - k - 1][y] - v[x][y];
			sum += col[x][y + k] - col[x][y - k - 1];
			tt.push_back(sum);
			y += s;
		}
		sx += s;
		ans.push_back(tt);
	}
	for (auto& i : ans)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}