#include <bits/stdc++.h>
#include <unordered_map>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef long double lb;

struct cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second == b.second)
		{
			return a.first > b.first;
		}
		return a.second > b.second;
	}

};

int dis[20001] = { 0, }, vertex = 0, edge = 0;;

void dijkstra(vector<pair<int, int>> graph[], int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
	for (int i = 1; i <= vertex; ++i)
	{
		dis[i] = INF;
	}
	dis[start] = 0;
	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		int current_vertex = cur.first;
		int current_weight = cur.second;
		pq.pop();
		if (dis[current_vertex] < current_weight)
		{
			continue;
		}
		for (auto& i : graph[current_vertex])
		{
			int next_vertex = i.first;
			int next_weight = i.second;
			if (dis[next_vertex] > dis[current_vertex] + next_weight)
			{
				dis[next_vertex] = dis[current_vertex] + next_weight;
				pq.push(make_pair(next_vertex, dis[next_vertex]));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int st = 0;
	cin >> vertex >> edge >> st;
	vector<pair<int, int>> graph[20001];
	for (int i = 0; i < edge; ++i)
	{
		int start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back(make_pair(end, weight));
	}
	dijkstra(graph, st);
	for (int i = 1; i <= vertex; ++i)
	{
		if (dis[i] == INF)
		{
			cout << "INF" << "\n";
		}
		else
		{
			cout << dis[i] << "\n";
		}
	}
	return 0;
}
