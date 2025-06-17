#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, st = -1;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (!temp)
		{
			st = i;
			continue;
		}
		graph[i].push_back(temp);
		graph[temp].push_back(i);
	}
	vector<int>cost(n + 1, 0), dist(n + 1, 0);
	vector<vector<bool>>visited(n + 1, vector<bool>(n + 1));
	vector<bool>leaf(n + 1, true);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	ll ok = 0;
	function<void(int, int)> dfs1 = [&](int parent, int node)
		{
			dist[node] = dist[parent] + 1;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				leaf[node] = false;
				dfs1(node, i);
			}
		};
	dfs1(0, st);
	function<void(int, int)> dfs2 = [&](int node, int pivot)
		{
			for (auto& i : graph[node])
			{
				if (dist[node] >= dist[i])
				{
					continue;
				}
				visited[pivot][i] = true;
				dfs2(i, pivot);
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		dfs2(i, i);
	}
	vector<ll>dp(n + 1, -1);
	function<ll(int)> dfs3 = [&](int node)
		{
			if (leaf[node])
			{
				return 1LL;
			}
			if (dp[node] != -1)
			{
				return dp[node];
			}
			ll res = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (visited[node][i] && dist[i] - dist[node] <= cost[node])
				{
					res = (res + dfs3(i)) % MOD;
				}
			}
			return dp[node] = res;
		};
	cout << dfs3(st);
	return 0;
}