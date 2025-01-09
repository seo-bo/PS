#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
	vector<pii>v(k + 1);
	for (int i = 1; i <= k; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	function<int(int, int)> dfs = [&](int cost, int depth)
		{
			if (cost == n)
			{
				return 1;
			}
			if (cost > n || depth > k)
			{
				return 0;
			}
			if (dp[cost][depth] != -1)
			{
				return dp[cost][depth];
			}
			int res = 0;
			for (int i = 0; i <= v[depth].second; ++i)
			{
				res += dfs(cost + i * v[depth].first, depth + 1);
			}
			return dp[cost][depth] = res;
		};
	cout << dfs(0, 1);
	return 0;
}