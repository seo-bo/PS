#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class LCA // https://github.com/seo-bo/Algorithm_templates/blob/main/LCA.cpp
{
private:
	int n, P;
	vector<int>depth;
	vector<ll>dist;
	vector<vector<int>>table;
	vector<vector<pair<int, ll>>>graph;
	void psh(int a, int b, ll w)
	{
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));
	}
	void dfs(int d, int parent, int node)
	{
		table[0][node] = parent; // <- 대회 끝난 후 고치기
		depth[node] = d;
		for (auto& [a, b] : graph[node])
		{
			if (a == parent)
			{
				continue;
			}
			dist[a] = dist[node] + b;
			dfs(d + 1, node, a);
		}
	}
	void build(int root)
	{
		dfs(0, 0, root);
		for (int i = 1; i < P; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				int mid = table[i - 1][j];
				table[i][j] = table[i - 1][mid];
			}
		}
	}
	int lca(int a, int b)
	{
		if (depth[a] < depth[b])
		{
			swap(a, b);
		}
		int diff = depth[a] - depth[b];
		for (int i = 0; diff; ++i, diff >>= 1)
		{
			if (diff & 1)
			{
				a = table[i][a];
			}
		}
		if (a == b)
		{
			return a;
		}
		for (int i = P - 1; i >= 0; --i)
		{
			if (table[i][a] != table[i][b])
			{
				a = table[i][a];
				b = table[i][b];
			}
		}
		return table[0][a];
	}
	ll distance(int a, int b)
	{
		return dist[a] + dist[b] - 2 * dist[lca(a, b)];
	}
public:
	LCA(int len)
	{
		n = len, P = 20;
		depth.resize(n + 1, 0);
		table.resize(P, vector<int>(n + 1));
		dist.resize(n + 1, 0);
		graph.resize(n + 1);
	}
	void add_edge(int u, int v, ll w = 1)
	{
		psh(u, v, w);
	}
	void init(int root = 1)
	{
		build(root);
	}
	int ancestor(int u, int v)
	{
		return lca(u, v);
	}
	ll get_dist(int u, int v)
	{
		return distance(u, v);
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, T = 0;
	cin >> n >> T;
	LCA lca(n);
	vector<int>v(T + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		lca.add_edge(a, b);
	}
	for (int i = 1; i <= T; ++i)
	{
		cin >> v[i];
	}
	lca.init();
	vector<int>dp(T + 1, 1);
	int ans = 1;
	for (int i = 1; i <= T; ++i)
	{
		for (int j = i + 1; j <= T; ++j)
		{
			if (lca.get_dist(v[i], v[j]) <= j - i)
			{
				dp[j] = max(dp[j], dp[i] + 1);
				ans = max(ans, dp[j]);
			}
		}
	}
	cout << ans;
	return 0;
}