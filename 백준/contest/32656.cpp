#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
	int v1 = 0, v2 = 0, lca = 0;
	cin >> v1 >> v2 >> lca;
	vector<int>parent(n + 1, 0), sub(n + 1, 0);
	function<void(int, int)> dfs = [&](int node, int pre)
		{
			parent[node] = pre;
			sub[node] = 1;
			for (auto& i : graph[node])
			{
				if (i != pre)
				{
					dfs(i, node);
					sub[node] += sub[i];
				}
			}
		};
	auto find = [&](int a, int b)
		{
			if (a == b)
			{
				return -1;
			}
			int node = b;
			while (parent[node] != a && parent[node] != -1)
			{
				node = parent[node];
			}
			if (parent[node] != a)
			{
				return -1;
			}
			return node;
		};
	dfs(lca, -1);
	ll ans = 0;
	if (v1 == v2)
	{
		if (lca == v1)
		{
			ans = n;
		}
	}
	else
	{
		if (lca == v1 || lca == v2)
		{
			int temp = (lca == v1) ? v2 : v1;
			int pivot = find(lca, temp);
			if (pivot != -1)
			{
				ans = n - sub[pivot];
			}
		}
		else
		{
			int pivot1 = find(lca, v1);
			int pivot2 = find(lca, v2);
			if (pivot1 != -1 && pivot2 != -1 && pivot1 != pivot2)
			{
				ans = n - sub[pivot1] - sub[pivot2];
			}
		}
	}
	cout << ans;
	return 0;
}
