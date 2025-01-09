#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<bool>in(n, false);
	for (int i = 0; i < m; ++i)
	{
		int temp = 0;
		cin >> temp;
		in[temp] = true;
	}
	vector<vector<int>>graph(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	function<bool(int, int)> path = [&](int parent, int node)
		{
			for (auto& i : graph[node])
			{
				if (i != parent)
				{
					in[node] = in[node] | path(node, i);
				}
			}
			return in[node];
		};
	path(-1, 0);
	vector<int>ans;
	function<void(int, int)> dfs = [&](int parent, int node)
		{
			ans.push_back(node);
			for (auto& i : graph[node])
			{
				if (i != parent && in[i])
				{
					dfs(node, i);
					ans.push_back(node);
				}
			}
		};
	dfs(-1, 0);
	cout << ans.size() - 1 << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}