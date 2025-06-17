#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	map<int, map<int, set<int>>>graph; // 정점, 간선, 정점집합
	map<int, set<int>>visited; // 정점, 간선집합
	map<int, map<int, int>>dist; // 정점, 간선, 정점
	vector<int>ans(n + 1, INT_MAX), dir = { -1,1 };
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a][c].insert(b);
		graph[b][c].insert(a);
	}
	queue<pii>q;
	for (auto& [a, b] : graph[1])
	{
		visited[1].insert(a);
		for (auto& i : b)
		{
			ans[i] = min(ans[i], 1);
			dist[i][a] = 1;
			q.push(make_pair(i, a));
		}
	}
	while (!q.empty())
	{
		auto [v, c] = q.front();
		q.pop();
		for (int i = 0; i < 2; ++i)
		{
			int nx = c + dir[i];
			if (graph[v].find(nx) == graph[v].end() || visited[v].find(nx) != visited[v].end())
			{
				continue;
			}
			visited[v].insert(nx);
			for (auto& j : graph[v][nx])
			{
				ans[j] = min(ans[j], dist[v][c] + 1);
				if (dist[j].find(nx) == dist[j].end())
				{
					dist[j][nx] = dist[v][c] + 1;
				}
				else
				{
					dist[j][nx] = min(dist[j][nx], dist[v][c] + 1);
				}
				q.push(make_pair(j, nx));
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ((ans[i] == INT_MAX) ? -1 : ans[i]) << ' ';
	}
	return 0;
}