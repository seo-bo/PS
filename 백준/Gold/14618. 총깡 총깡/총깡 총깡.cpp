#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

vector<pair<int, int>>graph[5001];
vector<int>A;
vector<int>B;
int visited[5001] = { 0, };
int mindis[5001] = { 0, };
int vertex = 0, edge = 0, home = 0;
int Adis = INF, Bdis = INF;

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
	for (int i = 0; i < 5001; i++)
	{
		mindis[i] = INF;
	}
	mindis[home] = 0;
	pq.push(make_pair(home, mindis[home]));
	while (!pq.empty())
	{
		int current_vertex = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (visited[current_vertex])
		{
			continue;
		}
		visited[current_vertex] = 1;
		for (auto& edge : graph[current_vertex])
		{
			int next_vertex = edge.first;
			int next_cost = cost + edge.second;
			if (mindis[next_vertex] > next_cost)
			{
				mindis[next_vertex] = next_cost;
				pq.push(make_pair(next_vertex, next_cost));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> vertex >> edge >> home;
	int animal = 0;
	cin >> animal;
	for (int i = 0; i < animal; ++i)
	{
		int temp = 0;
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < animal; ++i)
	{
		int temp = 0;
		cin >> temp;
		B.push_back(temp);
	}
	for (int i = 0; i < edge; ++i)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	dijkstra();
	for (auto i : A)
	{
		Adis = min(Adis, mindis[i]);
	}
	for (auto i : B)
	{
		Bdis = min(Bdis, mindis[i]);
	}
	if (Adis == INF && Bdis == INF) 
	{
		cout << -1;
	}
	else if (Adis <= Bdis) 
	{
		cout << 'A' << "\n" << Adis;
	}
	else 
	{
		cout << 'B' << "\n" << Bdis;
	}
	return 0;
}
