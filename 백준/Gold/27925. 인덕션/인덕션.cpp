#include <bits/stdc++.h>
#define INF 1e7
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	auto cal = [&](int pre, int nxt)
		{
			return min(max(pre, nxt) - min(pre, nxt), min(pre, nxt) + 10 - max(pre, nxt));
		};
	vector<vector<vector<vector<int>>>>dp(n + 1, vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(10, -1))));
	function<int(int, int, int, int)> dfs = [&](int idx, int x, int y, int z)
		{
			if (idx > n)
			{
				return 0;
			}
			if (dp[idx][x][y][z] != -1)
			{
				return dp[idx][x][y][z];
			}
			int res = INF, target = v[idx];
			res = min({ res, dfs(idx + 1, target, y, z) + cal(x,target), dfs(idx + 1, x, target, z) + cal(y,target)
				, dfs(idx + 1, x, y, target) + cal(z,target) });
			return dp[idx][x][y][z] = res;
		};
	cout << dfs(1, 0, 0, 0);
	return 0;
}