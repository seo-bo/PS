#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

class Edge
{
	public:
		int vertex;
		int weight;
		int id;
	Edge(int v, int w, int i) : vertex(v), weight(w), id(i) {}
};

vector<Edge>graph[1001];
int visited[1001];
int mindis[1001];
int vertex = 0, edge = 0, forbidden = 0, result = 0, origin = 0;

struct cmp_pq
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_pq>pq;
	for (int i = 1; i <= vertex; i++)
	{
		mindis[i] = INF;
	}
	mindis[start] = 0;
	pq.push(make_pair(start, mindis[start]));
	while (!pq.empty())
	{
		int current = pq.top().first;
		pq.pop();
		if (visited[current])
		{
			continue;
		}
		visited[current] = 1;
		for (auto& edge : graph[current])
		{
			int next = edge.vertex;
			int weight = edge.weight;
			if (edge.id == forbidden)
			{
				continue;
			}
			if (mindis[next] > mindis[current] + weight)
			{
				mindis[next] = mindis[current] + weight;
				pq.push(make_pair(next, mindis[next]));
			}
		}
	}
}

int main(void)
{
	cin >> vertex >> edge;
	for (int i = 1; i <= edge; i++)
	{
		int v = 0, u = 0, w = 0;
		cin >> v >> u >> w;
		graph[v].push_back(Edge(u, w, i));
		graph[u].push_back(Edge(v, w, i));
	}
	dijkstra(1);
	origin = mindis[vertex];
	forbidden++;
	for (int i = 1; i <= edge; i++)
	{
		memset(visited, 0, sizeof(visited));
		dijkstra(1);
		if (mindis[vertex] == INF)
		{
			result = INF;
			break;
		}
		result = max(result, abs(origin - mindis[vertex]));
		forbidden++;
	}
	if (result == INF)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
}
