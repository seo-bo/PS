#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>>graph(n + 1);
	vector<bool>ban(n + 1, false), visited(n + 1, false);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < m; ++i)
	{
		int temp = 0;
		cin >> temp;
		ban[temp] = true;
	}
	vector<vector<int>>dp(n + 1, vector<int>(k + 1, INT_MIN));
	function<void(int)> dfs = [&](int node)
		{
			vector<int>temp(k + 1, 0);
			for (auto& i : graph[node])
			{
				if (!visited[i])
				{
					visited[i] = true;
					dfs(i);
					vector<int>tp(k + 1, INT_MIN);
					for (int j = 0; j <= k; ++j)
					{
						for (int z = 0; z <= k - j; ++z)
						{
							if (dp[i][z] == INT_MIN)
							{
								continue;
							}
							tp[j + z] = max(tp[j + z], dp[i][z] + temp[j]);
						}
					}
					for (int j = 0; j <= k; ++j)
					{
						temp[j] = max(temp[j], tp[j]);
						if (temp[j] == INT_MIN)
						{
							temp[j] = 0;
						}
					}
				}
			}
			if (ban[node])
			{
				for (int i = 1; i <= k; ++i)
				{
					dp[node][i] = temp[i - 1] + 1;
				}
				dp[node][0] = 0;
			}
			else
			{
				for (int i = 0; i <= k; ++i)
				{
					dp[node][i] = temp[i] + 1;
				}
			}
		};
	visited[1] = true;
	dfs(1);
	int ans = 0;
	for (int i = 0; i <= k; ++i)
	{
		ans = max(ans, dp[1][i]);
	}
	cout << ans;
	return 0;
}