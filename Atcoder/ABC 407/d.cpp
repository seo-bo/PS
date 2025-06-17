#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>v(n, vector<ll>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	ll ans = LLONG_MIN;
	function<void(int, int, int)> dfs = [&](int pos, int depth, int limit)
		{
			if (depth == limit)
			{
				ll temp = 0;
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < m; ++j)
					{
						if (!visited[i][j])
						{
							temp ^= v[i][j];
						}
					}
				}
				ans = max(ans, temp);
				return;
			}
			if (pos == n * m)
			{
				return;
			}
			int x = pos / m;
			int y = pos % m;
			if (visited[x][y])
			{
				dfs(pos + 1, depth, limit);
				return;
			}
			dfs(pos + 1, depth, limit);
			if (y + 1 < m && !visited[x][y + 1])
			{
				visited[x][y] = visited[x][y + 1] = true;
				dfs(pos + 1, depth + 1, limit);
				visited[x][y] = visited[x][y + 1] = false;
			}
			if (x + 1 < n && !visited[x + 1][y])
			{
				visited[x][y] = visited[x + 1][y] = true;
				dfs(pos + 1, depth + 1, limit);
				visited[x][y] = visited[x + 1][y] = false;
			}
		};
	for (int i = 0; i <= 20; ++i)
	{
		dfs(0, 0, i);
	}
	cout << ans;
	return 0;
}
