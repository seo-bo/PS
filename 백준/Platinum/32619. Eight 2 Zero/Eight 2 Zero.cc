#include <bits/stdc++.h>
#define P 20
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>parent(n + 1, 0), rank(n + 1, 0), depth(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	vector<vector<int>>graph(n + 1), table(P, vector<int>(n + 1, 0));
	vector<pii>ex;
	function<int(int)> find = [&](int root)
		{
			return(parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			if (r1 != r2)
			{
				if (rank[r1] < rank[r2])
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
	function<void(int, int, int)> dfs = [&](int d, int parent, int node)
		{
			depth[node] = d;
			table[0][node] = parent;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				dfs(d + 1, node, i);
			}
		};
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
	auto cal = [&](int a, int b)
		{
			int c = lca(a, b);
			return depth[a] + depth[b] - 2 * depth[c];
		};
	auto sv = [&](int a, int b)
		{
			int c = lca(a, b);
			vector<int>ok;
			int x = a;
			while (x != c)
			{
				ok.push_back(x);
				x = table[0][x];
			}
			ok.push_back(c);
			vector<int>temp;
			x = b;
			while (x != c)
			{
				temp.push_back(x);
				x = table[0][x];
			}
			reverse(temp.begin(), temp.end());
			for (auto& i : temp)
			{
				ok.push_back(i);
			}
			return ok;
		};
	for (int i = 0; i < n + 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			merge(a, b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		else
		{
			ex.push_back(make_pair(a, b));
		}
	}
	dfs(0, 0, 1);
	for (int i = 1; i < P; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int mid = table[i - 1][j];
			table[i][j] = table[i - 1][mid];
		}
	}
	pii e1 = ex[0], e2 = ex[1];
	int a1 = cal(e1.first, e1.second) + 1, a2 = cal(e2.first, e2.second) + 1;
	vector<int> pa = sv(e1.first, e1.second);
	vector<int> pb = sv(e2.first, e2.second);
	set<int>ss(pa.begin(), pa.end());
	bool flag = true;
	for (auto& i : pb)
	{
		if (ss.find(i) != ss.end())
		{
			flag = false;
			break;
		}
	}
	vector<int>ans = { a1,a2,0,0 };
	if (flag)
	{
		ans[2] = ans[0] + ans[1];
	}
	else
	{
		set<pii>s;
		for (int i = 0; i < (int)pa.size() - 1; ++i)
		{
			int aa = pa[i], bb = pa[i + 1];
			if (aa > bb)
			{
				swap(aa, bb);
			}
			s.insert(make_pair(aa, bb));
		}
		int res = 0;
		for (int i = 0; i < (int)pb.size() - 1; ++i)
		{
			int aa = pb[i], bb = pb[i + 1];
			if (aa > bb)
			{
				swap(aa, bb);
			}
			if (s.find(make_pair(aa, bb)) != s.end())
			{
				res++;
			}
		}
		if (res > 0)
		{
			ans[3] = ans[0] + ans[1] - 2 * res;
		}
	}
	cout << n + 1 - *max_element(ans.begin(), ans.end());
	return 0;
}