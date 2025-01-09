#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1, vector<int>(n + 1, INT_MAX));
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			if (parent[root] == root)
			{
				return parent[root];
			}
			return parent[root] = find(parent[root]);
		};
	auto merge = [&](int root1, int root2)
		{
			int r1 = find(root1);
			int r2 = find(root2);
			if (r1 != r2)
			{
				if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
				}
				else
				{
					parent[r2] = r1;
					if (rank[r1] == rank[r2])
					{
						rank[r1]++;
					}
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
		int r1 = find(a), r2 = find(b);
		if (r1 != r2)
		{
			merge(a, b);
		}
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
				{
					if (graph[i][j] > graph[i][k] + graph[k][j])
					{
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
	}
	map<int, pii>ans;
	for (int i = 1; i <= n; ++i)
	{
		int id = find(i);
		int maxi = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (graph[i][j] == INT_MAX)
			{
				continue;
			}
			maxi = max(maxi, graph[i][j]);
		}
		if (ans.find(id) == ans.end())
		{
			ans[id] = make_pair(i, maxi);
		}
		else
		{
			if (ans[id].second > maxi)
			{
				ans[id] = make_pair(i, maxi);
			}
		}
	}
	vector<int>res;
	for (auto& [x, y] : ans)
	{
		res.push_back(y.first);
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto& i : res)
	{
		cout << i << '\n';
	}
	return 0;
}