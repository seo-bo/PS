#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, ans1 = 0, ans2 = 0, ans3 = 0;
	cin >> m >> n;
	unordered_map<int, int>mm;
	vector<vector<int>>v(n, vector<int>(m));
	vector<vector<int>>grid(n, vector<int>(m, 0));
	vector<vector<int>>dir = { {0,-1},{-1,0},{0,1},{1,0} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int area = 1;
	auto bfs = [&](int x, int y)
		{
			int cnt = 1;
			queue<pii>q;
			q.push(make_pair(x, y));
			grid[x][y] = area;
			while (!q.empty())
			{
				auto [a,b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					if (!(v[a][b] & (1 << i)))
					{
						int nx = a + dir[i][0];
						int ny = b + dir[i][1];
						if (nx >= 0 && ny >= 0 && nx < n && ny < m && !grid[nx][ny])
						{
							grid[nx][ny] = area;
							cnt++;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
			ans2 = max(ans2, cnt);
			mm[area] = cnt;
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!grid[i][j])
			{
				bfs(i, j);
				area++;
				ans1++;
			}
		}
	}
	ans3 = ans2;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (v[i][j] & (1 << k))
				{
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[i][j] != grid[nx][ny])
					{
						ans3 = max(ans3, mm[grid[i][j]] + mm[grid[nx][ny]]);
					}
				}
			}
		}
	}
	cout << ans1 << '\n' << ans2 << '\n' << ans3;
	return 0;
}