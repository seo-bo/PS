#include <bits/stdc++.h>
#define P 19
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, q = 0;
	cin >> n >> m;
	vector<int>parent(n + 1, 0), depth(n + 1, 0), rank(n + 1, 0);
	vector<vector<int>>table(P, vector<int>(n + 1, 0));
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			if (r1 != r2)
			{
				if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
				}
				else
				{
					parent[r1] = r2;
					if (rank[r1] == rank[r2])
					{
						rank[r2]++;
					}
				}
			}
		};
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			merge(a, b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	function<void(int, int, int)> dfs = [&](int d, int p, int node)
		{
			table[0][node] = p;
			depth[node] = d;
			for (auto& i : graph[node])
			{
				if (i != p)
				{
					dfs(d + 1, node, i);
				}
			}
		};
	dfs(0, 0, 1);
	auto lca = [&](int a, int b)
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
		};
	for (int i = 1; i < P; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int mid = table[i - 1][j];
			table[i][j] = table[i - 1][mid];
		}
	}
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int c = lca(a, b);
		cout << (depth[a] + depth[b] - 2 * depth[c]) - 1 << '\n';
	}
	return 0;
}