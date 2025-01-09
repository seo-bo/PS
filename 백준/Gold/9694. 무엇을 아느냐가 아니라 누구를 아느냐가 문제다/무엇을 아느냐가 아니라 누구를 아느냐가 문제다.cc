#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

struct cmps
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

vector<pair<int, int>>graph[21];
int visited[21] = { 0, };
int mindis[21] = { 0, };
int path[21] = { 0, };
int result[21] = { 0, };
int vertex = 0, edge = 0;
void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmps>pq;
	for (int i = 0; i <= vertex; ++i)
	{
		mindis[i] = INF;
		path[i] = -1;
	}
	mindis[0] = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty())
	{
		int current_vertex = pq.top().first;
		pq.pop();
		if (visited[current_vertex])
		{
			continue;
		}
		visited[current_vertex] = 1;
		for (auto& edge : graph[current_vertex])
		{
			int next_vertex = edge.first;
			int next_cost = edge.second;
			if (mindis[next_vertex] > mindis[current_vertex] + next_cost)
			{
				mindis[next_vertex] = mindis[current_vertex] + next_cost;
				path[next_vertex] = current_vertex;
				pq.push(make_pair(next_vertex, mindis[next_vertex]));
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	for (int z = 1; z <= test; ++z)
	{
		int idx = 0;
		memset(result, 0, sizeof(result));
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
		cin >> edge >> vertex;
		for (int i = 0; i < edge; ++i)
		{
			int u = 0, v = 0, w = 0;
			cin >> u >> v >> w;
			graph[u].push_back(make_pair(v, w));
			graph[v].push_back(make_pair(u, w));
		}
		dijkstra();
		if (mindis[vertex - 1] == INF)
		{
			cout << "Case #" << z << ": " << "-1" << "\n";
			continue;
		}
		cout << "Case #" << z << ": ";
		
		for (int i = vertex - 1; i != -1; i = path[i])
		{
			result[idx++] = i;
		}
		for (int i = idx - 1; i >= 0; i--)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}