#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;

class Cost
{
public:
	vector<pair<int, int>>graph[1001];
	ll mindis[1001];
	int vertex, edge;

	Cost(int vertex, int edge) : vertex(vertex + 1), edge(edge) {}

	void insert(int start, int end, int weight)
	{
		this->graph[start].push_back(make_pair(end, weight));
		this->graph[end].push_back(make_pair(start, weight));
	}

	void dijkstra(int start)
	{
		priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		fill(mindis, mindis + this->vertex, INF);
		mindis[start] = 0;
		pq.push(make_pair(0, start));
		while (!pq.empty())
		{
			int weight = pq.top().first;
			int current_vertex = pq.top().second;
			pq.pop();
			if (mindis[current_vertex] < weight)
			{
				continue;
			}
			for (auto& i : graph[current_vertex])
			{
				int next_vertex = i.first;
				int next_weight = weight + i.second;
				if (next_weight < mindis[next_vertex])
				{
					mindis[next_vertex] = next_weight;
					pq.push(make_pair(next_weight, next_vertex));
				}
			}
		}
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int vertex = 0, edge = 0;
	cin >> vertex >> edge;
	Cost solve(vertex, edge);
	for (int i = 0; i < edge; ++i)
	{
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		solve.insert(start, end, weight);
	}
	int root1 = 0, root2 = 0;
	cin >> root1 >> root2;
	solve.dijkstra(1);
	ll to_1 = solve.mindis[root1];
	ll to_2 = solve.mindis[root2];
	solve.dijkstra(root1);
	ll root1_to_2 = solve.mindis[root2];
	ll root1_to_v = solve.mindis[vertex];
	solve.dijkstra(root2);
	ll root2_to_v = solve.mindis[vertex];
	ll result1 = to_1 + root1_to_2 + root2_to_v;
	ll result2 = to_2 + root1_to_2 + root1_to_v;
	cout << ((result1 >= INF && result2 >= INF) ? -1 : min(result1, result2));
	return 0;
}