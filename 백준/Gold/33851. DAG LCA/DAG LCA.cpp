#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	auto bfs = [&](int node)
		{
			queue<int>q;
			q.push(node);
			vector<int>visited(n + 1, INT_MAX);
			visited[node] = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto& i : graph[cur])
				{
					if (visited[i] > visited[cur] + 1)
					{
						visited[i] = visited[cur] + 1;
						q.push(i);
					}
				}
			}
			return visited;
		};
	vector<vector<int>>dist(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = bfs(i);
	}
	while (q--)
	{
		int a = 0, b = 0, ans = INT_MAX;
		cin >> a >> b;
		for (int i = 1; i <= n; ++i)
		{
			ans = min(ans, max(dist[i][a], dist[i][b]));
		}
		cout << ((ans == INT_MAX) ? -1 : ans) << '\n';
	}
	return 0;
}