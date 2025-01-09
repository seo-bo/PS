#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, start = 0;
	cin >> n >> start;
	vector<ll>cost(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, -1));
	function<ll(int, int, int)> dfs = [&](int parent, int node, int sp)
		{
			if (dp[node][sp] != -1)
			{
				return dp[node][sp];
			}
			ll res = 0;
			for (auto& i : graph[node])
			{
				if (i != parent)
				{
					res += min(dfs(node, i, i) + cost[i], dfs(node, i, sp) + cost[i] - cost[sp]);
				}
			}
			return dp[node][sp] = res;
		};
	cout << dfs(-1, start, start) + cost[start];
	return 0;
}