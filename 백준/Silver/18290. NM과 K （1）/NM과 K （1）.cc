#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int ans = INT_MIN;
	function<void(int, int, int, int)> dfs = [&](int x, int y, int depth, int sum)
		{
			if (depth == k)
			{
				ans = max(ans, sum);
				return;
			}
			if (y >= m)
			{
				if (x + 1 >= n)
				{
					return;
				}
				x++;
				y = 0;
			}
			for (int i = x; i < n; ++i)
			{
				for (int j = (i == x ? y : 0); j < m; ++j)
				{
					if (!i || !visited[i - 1][j])
					{
						visited[i][j] = true;
						dfs(i, j + 2, depth + 1, sum + v[i][j]);
						visited[i][j] = false;
					}
				}
			}
		};
	dfs(0, 0, 0, 0);
	cout << ans;
	return 0;
}