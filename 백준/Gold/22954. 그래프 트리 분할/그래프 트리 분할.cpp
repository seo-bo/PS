#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	auto fail = [&]
		{
			cout << -1;
			exit(0);
		};
	if (n <= 2)
	{
		fail();
	}
	vector<int>parent(n + 1, 0);
	vector<int>rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	vector<vector<pii>>graph(n + 1);
	vector<bool>visited(n + 1, 0);
	vector<int>p(2);
	vector<vector<int>>vertexs(2);
	vector<vector<int>>edges(2);
	vector<pii>leaf;
	function<int(int)> find = [&](int root) ->int
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
				if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
				}
				else if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
				}
				else
				{
					parent[r1] = r2;
					rank[r2]++;
				}
			}
		};
	function<int(int, vector<int>&, vector<int>&)> dfs = [&](int node, vector<int>& t, vector<int>& e)->int
		{
			if (graph[node].size() == 1)
			{
				leaf.push_back(make_pair(node, graph[node].back().second));
			}
			int cnt = 1;
			for (auto& [i, j] : graph[node])
			{
				if (!visited[i])
				{
					visited[i] = true;
					t.push_back(i);
					e.push_back(j);
					cnt += dfs(i, t, e);
				}
			}
			return cnt;
		};
	for (int i = 1; i <= m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int r1 = find(a), r2 = find(b);
		if (r1 != r2)
		{
			merge(a, b);
			graph[a].push_back(make_pair(b, i));
			graph[b].push_back(make_pair(a, i));
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			if (cnt == 2)
			{
				fail();
			}
			visited[i] = true;
			vertexs[cnt].push_back(i);
			p[cnt] = dfs(i, vertexs[cnt], edges[cnt]);
			cnt++;
		}
	}
	auto print = [&](int _, int uv, int ud)
		{
			for (int o = 0; o < _; ++o)
			{
				for (auto& i : vertexs[o])
				{
					if (i == uv)
					{
						continue;
					}
					cout << i << ' ';
				}
				cout << '\n';
				for (auto& i : edges[o])
				{
					if (i == ud)
					{
						continue;
					}
					cout << i << ' ';
				}
				cout << '\n';
			}
		};
	if (cnt == 1)
	{
		cout << 1 << ' ' << p[0] - 1 << '\n';
		auto [uv, ud] = leaf[0];
		cout << uv << '\n';
		print(cnt, uv, ud);
	}
	else if (cnt == 2)
	{
		if (p[0] == p[1])
		{
			fail();
		}
		cout << p[0] << ' ' << p[1] << '\n';
		print(cnt, -1, -1);
	}
	return 0;
}