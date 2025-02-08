#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, ans = 0;
	cin >> m >> n;
	vector<vector<int>>v(n, vector<int>(m));
	vector<vector<int>>odd = { {-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0} };
	vector<vector<int>>even = { {-1,0}, {-1,1},{0,-1},{0,1},{1,0},{1,1} };
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (1 <= j && j <= m - 2 && 1 <= i && i <= n - 2)
			{
				continue;
			}
			if (!visited[i][j] && !v[i][j])
			{
				visited[i][j] = true;
				queue<pii>q;
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					auto [x, y] = q.front();
					q.pop();
					for (int k = 0; k < 6; ++k)
					{
						int nx = x + ((x % 2) ? odd[k][0] : even[k][0]);
						int ny = y + ((x % 2) ? odd[k][1] : even[k][1]);
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v[nx][ny] && !visited[nx][ny])
						{
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
	auto sv = [&](int x, int y)
		{
			int cnt = 0;
			for (int i = 0; i < 6; ++i)
			{
				int nx = x + ((x % 2) ? odd[i][0] : even[i][0]);
				int ny = y + ((x % 2) ? odd[i][1] : even[i][1]);
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny])
				{
					cnt++;
				}
			}
			return cnt;
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!v[i][j])
			{
				if (!visited[i][j])
				{
					ans -= sv(i, j);
				}
				continue;
			}
			ans += (6 - sv(i, j));
		}
	}
	cout << ans;
	return 0;
}
