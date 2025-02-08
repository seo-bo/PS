#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

vector<pair<int, int>>graph[501];
vector<int> node[501];
int mindis[501] = { 0, };
int visited[501] = { 0, };
int vertex = 0, edge = 0, init = 0, fin = 0;

struct cmps
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

void dijkstra()
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmps>pq;
	for (int i = 0; i < 501; i++)
	{
		mindis[i] = INF;
	}
	mindis[init] = 0;
	pq.push(make_pair(init, mindis[init]));
	while (!pq.empty())
	{
		int current_vertex = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		for (auto& edge : graph[current_vertex])
		{
			int next_vertex = edge.first;
			int next_cost = cost + edge.second;
			if (mindis[next_vertex] > next_cost)
			{
				mindis[next_vertex] = next_cost;
				pq.push(make_pair(next_vertex, next_cost));
				vector<int>().swap(node[next_vertex]);
				node[next_vertex].push_back(current_vertex);
			}
			else if (mindis[next_vertex] == next_cost)
			{
				node[next_vertex].push_back(current_vertex);
			}
		}
	}
}

void bfs(int end)
{
	queue<int>q;
	q.push(end);
	while (!q.empty())
	{
		end = q.front();
		q.pop();
		if (visited[end])
		{
			continue;
		}
		visited[end] = 1;
		for (auto& i : node[end])
		{
			for (auto& j : graph[i])
			{
				if (j.first == end)
				{
					j.second = INF;
				}
				q.push(i);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1)
	{
		memset(visited, 0, sizeof(visited));
		memset(graph, 0, sizeof(graph));
		memset(node, 0, sizeof(node));
		cin >> vertex >> edge;
		if (vertex == 0 && edge == 0)
		{
			return 0;
		}
		cin >> init >> fin;
		for (int i = 0; i < edge; ++i)
		{
			int u = 0, v = 0, w = 0;
			cin >> u >> v >> w;
			graph[u].push_back(make_pair(v, w));
		}
		dijkstra();
		bfs(fin);
		dijkstra();
		if (mindis[fin] == INF)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << mindis[fin] << "\n";
		}
	}
	return 0;
}