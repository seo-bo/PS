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
	int r = 0, c = 0;
	cin >> r >> c;
	vector<vector<char>>grid(r, vector<char>(c));
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> grid[i][j];
		}
	}
	int ans = 1;
	vector<bool>visited(30);
	visited[grid[0][0] - 'A'] = true;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,1},{0,-1} };
	function<void(int, int, int)> dfs = [&](int x, int y, int cnt) -> void
		{
			ans = max(ans, cnt);
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c)
				{
					if (!visited[grid[nx][ny] - 'A'])
					{
						visited[grid[nx][ny] - 'A'] = true;
						dfs(nx, ny, cnt + 1);
						visited[grid[nx][ny] - 'A'] = false;
					}
				}
			}
		};
	dfs(0, 0, 1);
	cout << ans;
	return 0;
}