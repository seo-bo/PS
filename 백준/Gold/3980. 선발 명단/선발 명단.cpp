#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		vector<vector<pii>>graph(11);
		vector<vector<int>>dp(1 << 11, vector<int>(11, -1));
		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				int temp = 0;
				cin >> temp;
				if (temp)
				{
					graph[i].push_back(make_pair(j, temp));
				}
			}
		}
		function<int(int, int)> dfs = [&](int mask, int node)
			{
				if (mask == (1 << 11) - 1 || node == 11)
				{
					return 0;
				}
				if (dp[mask][node] != -1)
				{
					return dp[mask][node];
				}
				int cost = -1e6;
				for (auto& [a, b] : graph[node])
				{
					if (!(mask & (1 << a)))
					{
						cost = max(cost, dfs(mask | (1 << a), node + 1) + b);
					}
				}
				return dp[mask][node] = cost;
			};
		cout << dfs(0, 0) << '\n';
	}
	return 0;
}