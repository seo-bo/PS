#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, x = 0, y = 0, d = 0;
	cin >> n >> m >> x >> y >> d;
	vector<vector<int>>grid(n, vector<int>(m, 0));
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	vector<vector<int>>dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 북 동 남 서
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	visited[x][y] = true;
	int ans = 1;
	while (1)
	{
		bool check = false;
		for (int i = 0; i < 4; ++i)
		{
			d = (d + 3) % 4;
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !grid[nx][ny] && !visited[nx][ny])
			{
				x = nx, y = ny, check = true;
				visited[x][y] = true;
				ans++;
				break;
			}
		}
		if (!check)
		{
			int nx = x - dir[d][0];
			int ny = y - dir[d][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny])
			{
				break;
			}
			x = nx, y = ny;
		}
	}
	cout << ans;
	return 0;
}