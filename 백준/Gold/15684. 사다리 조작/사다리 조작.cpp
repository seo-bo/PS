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
	int n = 0, m = 0, h = 0, ans = 0;
	cin >> n >> m >> h;
	vector<vector<bool>>visited(h + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		visited[a][b] = true;
	}
	vector<pii>v;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (!visited[i][j] && !visited[i][j - 1] && !visited[i][j + 1])
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	auto check = [&]()->bool
		{
			for (int i = 1; i <= n; ++i)
			{
				int x = 1, y = i;
				while (x <= h)
				{
					if (y > 1 && visited[x][y - 1])
					{
						y--;
					}
					else if (y < n && visited[x][y])
					{
						y++;
					}
					x++;
				}
				if (y != i)
				{
					return false;
				}
			}
			return true;
		};
	function<void(int, int, int)> dfs = [&](int depth, int start, int end) ->void
		{
			if (depth == end)
			{
				if (check())
				{
					cout << end;
					exit(0);
				}
				return;
			}
			int siz = v.size();
			for (int i = start; i < siz; ++i)
			{
				auto [a, b] = v[i];
				if (!visited[a][b] && !visited[a][b - 1] && !visited[a][b + 1])
				{
					visited[a][b] = true;
					dfs(depth + 1, i + 1, end);
					visited[a][b] = false;
				}
			}
		};
	for (int i = 0; i <= 3; ++i)
	{
		dfs(0, 0, i);
	}
	cout << -1;
	return 0;
}