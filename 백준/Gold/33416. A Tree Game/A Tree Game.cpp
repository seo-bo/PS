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
	if (graph[1].size() == 1)
	{
		cout << 1;
		return 0;
	}
	function<bool(int, int)> dfs = [&](int parent, int node)
		{
			if (graph[node].size() == 1)
			{
				return true;
			}
			int cnt = 0;
			for (auto& i : graph[node])
			{
				if (i != parent)
				{
					if (dfs(node, i))
					{
						cnt++;
					}
				}
			}
			return (cnt >= 2);
		};
	cout << dfs(0, 1);
	return 0;
}