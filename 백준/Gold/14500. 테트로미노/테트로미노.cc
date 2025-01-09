#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // T형은 분기때문에 안될거같은데.. 중간점 기준으로?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<vector<int>>>tet = { {{0,-1},{0,1},{1,0}},{{-1,0},{1,0},{0,1}},{{0,-1},{0,1},{-1,0}},{{-1,0},{1,0},{0,-1}} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	int ans = 0;
	function<void(int, int, int, int)> dfs = [&](int x, int y, int depth, int sum)
		{
			if (depth == 4)
			{
				ans = max(ans, sum);
				return;
			}
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (!visited[nx][ny])
					{
						visited[nx][ny] = true;
						dfs(nx, ny, depth + 1, sum + v[nx][ny]);
						visited[nx][ny] = false;
					}
				}
			}
		};
	auto te = [&](int x, int y)
		{
			int sum = 0;
			for (int i = 0; i < 4; ++i)
			{
				int temp = v[x][y];
				for (int j = 0; j < 3; ++j)
				{
					int nx = x + tet[i][j][0];
					int ny = y + tet[i][j][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m)
					{
						temp += v[nx][ny];
					}
					else
					{
						temp = INT_MIN;
						break;
					}
				}
				sum = max(temp, sum);
			}
			ans = max(sum, ans);
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			visited[i][j] = true;
			dfs(i, j, 1, v[i][j]);
			visited[i][j] = false;
			te(i, j);
		}
	}
	cout << ans;
	return 0;
}