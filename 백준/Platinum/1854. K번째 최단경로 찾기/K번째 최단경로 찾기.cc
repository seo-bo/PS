#include <bits/stdc++.h>

using namespace std;

priority_queue<int>dis[1001];
vector<pair<int, int>>graph[1001];
int vertex = 0, edge = 0, k = 0;

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
	pq.push(make_pair(1, 0)); // 1부터 출발하고 가중치는 0
	dis[1].push(0); 
	while (!pq.empty()) // 사이클 돌수도 있어서 방문처리 X
	{
		int current_vertex = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		for (auto& edge : graph[current_vertex])
		{
			int next_vertex = edge.first;
			int next_cost = cost + edge.second;
			if (dis[next_vertex].size() < k) // 딱 k만큼 저장
			{
				dis[next_vertex].push(next_cost);
				pq.push(make_pair(next_vertex, next_cost));
			}
			else if (dis[next_vertex].top() > next_cost)
			{
				dis[next_vertex].pop();
				dis[next_vertex].push(next_cost);
				pq.push(make_pair(next_vertex, next_cost));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> vertex >> edge >> k;
	for (int i = 0; i < edge; ++i)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
	dijkstra();
	for (int i = 1; i <= vertex; ++i)
	{
		if (dis[i].size() < k)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << dis[i].top() << "\n";
		}
	}
	return 0;
}