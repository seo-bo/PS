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
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		cin >> a >> b >> c >> d >> e;
		int cost = c + max(0, e - 10) * d;
		graph[a].push_back(make_pair(b, cost));
	}
	vector<int>dist(n + 1, INT_MAX);
	dist[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		auto [co, ver] = pq.top();
		pq.pop();
		if (dist[ver] < co)
		{
			continue;
		}
		for (auto& [nv, nc] : graph[ver])
		{
			if (dist[nv] > nc + co)
			{
				dist[nv] = nc + co;
				pq.push(make_pair(dist[nv], nv));
			}
		}
	}
	if (dist[n] == INT_MAX)
	{
		cout << "It is not a great way.";
		return 0;
	}
	cout << dist[n] << ' ';
	vector<vector<int>>temp(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (auto& [nv, nc] : graph[i])
		{
			if (dist[nv] != INT_MAX && dist[i] != INT_MAX && dist[nv] == dist[i] + nc)
			{
				temp[i].push_back(nv);
			}
		}
	}
	queue<int>q;
	vector<int>visited(n + 1, INT_MAX);
	q.push(1);
	visited[1] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == n)
		{
			cout << visited[cur];
			return 0;
		}
		for (auto& i : temp[cur])
		{
			if (visited[i] > visited[cur] + 1)
			{
				visited[i] = visited[cur] + 1;
				q.push(i);
			}
		}
	}
	return 0;
}