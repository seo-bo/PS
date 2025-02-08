#include <bits/stdc++.h>
#define P 19
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	vector<ll>dist(n + 1, 0);
	vector<int>depth(n + 1, 0);
	vector<vector<int>>table(P, vector<int>(n + 1, 0));
	function<void(int, int, int)> dfs = [&](int parent, int node, int lv)
		{
			table[0][node] = parent;
			depth[node] = lv;
			for (auto& [a, b] : graph[node])
			{
				if (a == parent)
				{
					continue;
				}
				dist[a] = dist[node] + b;
				dfs(node, a, lv + 1);
			}
		};
	dfs(0, 1, 0);
	for (int i = 1; i < P; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int mid = table[i - 1][j];
			table[i][j] = table[i - 1][mid];
		}
	}
	auto lca = [&](int a, int b)
		{
			if (depth[a] < depth[b])
			{
				swap(a, b);
			}
			int diff = depth[a] - depth[b];
			for (int i = 0; diff; ++i)
			{
				if (diff & 1)
				{
					a = table[i][a];
				}
				diff >>= 1;
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
	auto query = [&](int a, int b)
		{
			for (int i = 0; b; ++i)
			{
				if (b & 1)
				{
					a = table[i][a];
				}
				b >>= 1;
			}
			return a;
		};
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		int l = lca(b, c);
		if (a == 1)
		{
			cout << dist[b] + dist[c] - 2LL * dist[l] << '\n';
		}
		else
		{
			int k = 0;
			cin >> k;
			int pivot = depth[b] - depth[l] + 1;
			int siz = depth[b] + depth[c] - 2 * depth[l] + 1;
			if (k <= pivot)
			{
				cout << query(b, k - 1) << '\n';
			}
			else
			{
				cout << query(c, siz - k) << '\n';
			}
		}
	}
	return 0;
}