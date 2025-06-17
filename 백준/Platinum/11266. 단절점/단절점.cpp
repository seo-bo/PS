#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, cnt = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<int>num(n + 1), low(n + 1);
	set<int>s;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	function<void(int, int)> dfs = [&](int parent, int node)
		{
			num[node] = low[node] = ++cnt;
			int ok = 0;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				if (!num[i])
				{
					ok++;
					dfs(node, i);
					low[node] = min(low[node], low[i]);
					if (parent != -1 && low[i] >= num[node])
					{
						s.insert(node);
					}
				}
				else
				{
					low[node] = min(low[node], num[i]);
				}
			}
			if (parent == -1 && ok >= 2)
			{
				s.insert(node);
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!num[i])
		{
			dfs(-1, i);
		}
	}
	cout << s.size() << '\n';
	for (auto& i : s)
	{
		cout << i << ' ';
	}
	return 0;
}