#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0, co = 1;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, 0));
		if (c)
		{
			co = 0;
		}
		graph[b].push_back(make_pair(a, co));
	}
	vector<vector<int>>dist(n + 1, vector<int>(n + 1, INT_MAX));
	auto dijkstra = [&](int start)
		{
			priority_queue<pii, vector<pii>, greater<pii>>pq;
			pq.push(make_pair(0, start));
			dist[start][start] = 0;
			while (!pq.empty())
			{
				auto [co, ver] = pq.top();
				pq.pop();
				if (dist[start][ver] < co)
				{
					continue;
				}
				for (auto& [nv, nc] : graph[ver])
				{
					if (dist[start][nv] > dist[start][ver] + nc)
					{
						dist[start][nv] = dist[start][ver] + nc;
						pq.push(make_pair(dist[start][nv], nv));
					}
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		dijkstra(i);
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}
	return 0;
}