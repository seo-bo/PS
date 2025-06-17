#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0, a = 0, b = 0;
	vector<bool>visited(n + 1, false);
	function<void(int)> dfs = [&](int node)
		{
			visited[node] = true;
			a++;
			for (auto& i : graph[node])
			{
				b++;
				if (visited[i])
				{
					continue;
				}
				dfs(i);
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			a = b = 0;
			dfs(i);
			ans += b / 2 - a + 1;
		}
	}
	cout << ans;
	return 0;
}
