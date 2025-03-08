#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<char, int>mm = { {'A',0},{'B',1},{'C',2},{'D',3},{'F',4} };
	vector<vector<int>>cost = { {10,8,7,5,1},{8,6,4,3,1},{7,4,3,2,1},
		{5,3,2,2,1},{1,1,1,1,0} };
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = mm[temp[j]];
		}
	}
	vector<vector<int>>dp(n * m, vector<int>((1 << m), -1));
	function<int(int, int)> dfs = [&](int idx, int mask)
		{
			if (idx >= n * m)
			{
				return 0;
			}
			if (dp[idx][mask] != -1)
			{
				return dp[idx][mask];
			}
			int res = dfs(idx + 1, (mask >> 1));
			int x = idx / m, y = idx % m;
			if (!(mask & 1))
			{
				if (x + 1 < n)
				{
					int a = v[x][y], b = v[x + 1][y];
					res = max(res, cost[a][b] + dfs(idx + 1, (mask >> 1) | (1 << (m - 1))));
				}
				if (!(mask & 3) && y + 1 < m)
				{
					int a = v[x][y], b = v[x][y + 1];
					res = max(res, cost[a][b] + dfs(idx + 2, (mask >> 2)));
				}
			}
			return dp[idx][mask] = res;
		};
	cout << dfs(0, 0);
	return 0;
}