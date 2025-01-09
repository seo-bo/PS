#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<vector<ll>>cost(n + 1, vector<ll>(4, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cin >> cost[i][j];
		}
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(4, 0));
	vector<int>parent(n + 1, -1);
	function<void(int)> dfs = [&](int node)
		{
			for (auto& i : graph[node])
			{
				if (i != parent[node])
				{
					parent[i] = node;
					dfs(i);
					for (int j = 1; j <= 3; ++j)
					{
						ll pivot = 0;
						for (int k = 1; k <= 3; ++k)
						{
							if (k != j)
							{
								pivot = max(pivot, dp[i][k]);
							}
						}
						dp[node][j] += pivot;
					}
				}
			}
			for (int i = 1; i <= 3; ++i)
			{
				dp[node][i] += cost[node][i];
			}
		};
	dfs(1);
	int color = 1;
	for (int i = 2; i <= 3; ++i)
	{
		if (dp[1][i] > dp[1][color])
		{
			color = i;
		}
	}
	ll ans = dp[1][color];
	string cans(n + 1, 'R');
	function<void(int, int)> dfs2 = [&](int node, int pre)
		{
			cans[node] = (pre == 1) ? 'R' : (pre == 2) ? 'G' : 'B';
			for (auto& i : graph[node])
			{
				if (i != parent[node])
				{
					int cl = 1;
					ll pivot = 0;
					for (int j = 1; j <= 3; ++j)
					{
						if (j == pre)
						{
							continue;
						}
						if (dp[i][j] > pivot)
						{
							cl = j;
							pivot = dp[i][j];
						}
					}
					dfs2(i, cl);
				}
			}
		};
	dfs2(1, color);
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i)
	{
		cout << cans[i];
	}
	return 0;
}