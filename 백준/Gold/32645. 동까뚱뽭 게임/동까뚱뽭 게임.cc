#include <bits/stdc++.h>
using namespace std;

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
	vector<bool>dp(n + 1, false);
	function<bool(int, int)> dfs = [&](int parent, int node)
		{
			bool flag = false;
			for (auto& i : graph[node])
			{
				if (i != parent)
				{
					dfs(node, i);
					if (!dp[i])
					{
						flag = true;
					}
				}
			}
			return dp[node] = flag;
		};
	dfs(-1, 1);
	for (int i = 1; i <= n; i++)
	{
		if (dp[i])
		{
			cout << "donggggas" << '\n';
		}
		else
		{
			cout << "uppercut" << '\n';
		}
	}
	return 0;
}