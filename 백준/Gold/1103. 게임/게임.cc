#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; ++j)
		{
			if (a[j] == 'H')
			{
				v[i][j] = -1;
			}
			else
			{
				v[i][j] = a[j] - '0';
			}
		}
	}
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	vector<vector<int>>dp(n, vector<int>(m, -1));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	function<int(int, int)> dfs = [&](int x, int y)->int
		{
			if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == -1)
			{
				return 0;
			}
			if (visited[x][y])
			{
				return -1;
			}
			if (dp[x][y] != -1)
			{
				return dp[x][y];
			}
			visited[x][y] = true;
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0] * v[x][y];
				int ny = y + dir[i][1] * v[x][y];
				int ans = dfs(nx, ny);
				if (ans == -1)
				{
					return -1;
				}
				dp[x][y] = max(dp[x][y], ans);
			}
			visited[x][y] = false;
			return dp[x][y] = dp[x][y] + 1;
		};
	cout << dfs(0, 0);
	return 0;
}