#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	int st = 0, ed = 0;
	cin >> st >> ed;
	set<int>s;
	auto dijkstra = [&](int node)
		{
			vector<int>dist(n + 1, INT_MAX);
			dist[node] = 0;
			priority_queue<pii, vector<pii>, greater<pii>>pq;
			pq.push(make_pair(0, node));
			while (!pq.empty())
			{
				auto [co, ve] = pq.top();
				pq.pop();
				if (dist[ve] < co)
				{
					continue;
				}
				for (auto& [nv, nc] : graph[ve])
				{
					if (s.find(nv) != s.end())
					{
						continue;
					}
					int temp = dist[ve] + nc;
					if (dist[nv] > temp)
					{
						dist[nv] = temp;
						pq.push(make_pair(dist[nv], nv));
					}
				}
			}
			return dist;
		};
	vector<int>dist = dijkstra(st);
	vector<int>rev = dijkstra(ed);
	int ans = dist[ed];
	queue<int>q;
	q.push(st);
	vector<bool>visited(n + 1, false);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == ed)
		{
			break;
		}
		s.insert(cur);
		visited[cur] = true;
		int temp = INT_MAX;
		for (auto& [a, b] : graph[cur])
		{
			if (dist[a] != INT_MAX && rev[a] != INT_MAX)
			{
				if (dist[a] == dist[cur] + b && dist[a] + rev[a] == ans)
				{
					temp = min(temp, a);
				}
			}
		}
		q.push(temp);
	}
	s.erase(st);
	vector<int>res = dijkstra(ed);
	cout << ans + res[st];
	return 0;
}