#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<char>>v(n, vector<char>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	int ans = 0;
	function<void(int, int, int)> dfs = [&](int x, int y, int cnt)
		{
			if (cnt == k)
			{
				ans++;
				return;
			}
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && v[nx][ny] == '.')
				{
					visited[nx][ny] = true;
					dfs(nx, ny, cnt + 1);
					visited[nx][ny] = false;
				}
			}
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == '.')
			{
				visited[i][j] = true;
				dfs(i, j, 0);
				visited[i][j] = false;
			}
		}
	}
	cout << ans;
	return 0;
}
