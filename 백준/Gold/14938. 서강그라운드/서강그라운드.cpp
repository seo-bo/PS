#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

vector<pair<int, int>>graph[101];
int dismin[101] = { 0, };
int visited[101] = { 0, };
int getitem[101] = { 0, };

struct Comp 
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) 
    {
        return a.second > b.second;
    }
};

void dijkstra(int start)
{
    priority_queue < pair<int, int>, vector<pair<int, int>>, Comp>pq;
    for (int i = 0; i < 101; i++)
    {
        dismin[i] = INF;
    }
    dismin[start] = 0;
    pq.push({ start, dismin[start]});
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
            int weight = edge.second;
            if (dismin[next_vertex] > dismin[current_vertex] + weight)
            {
                dismin[next_vertex] = dismin[current_vertex] + weight;
                pq.push({ next_vertex , dismin[next_vertex]});
            }
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int vertex = 0, range = 0, edge = 0;
    long long result = 0;
    cin >> vertex >> range >> edge;
    for (int i = 1; i <= vertex; ++i)
    {
        cin >> getitem[i];
    }
    for (int i = 0; i < edge; ++i)
    {
        int u = 0, v = 0, w = 0;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }
    for (int i = 1; i <= vertex; ++i)
    {
        long long sum = 0;
        dijkstra(i);
        for (int j = 1; j <= vertex; ++j)
        {
            if (dismin[j] <= range)
            {
                sum += getitem[j];
            }
        }
        result = max(result, sum);
        memset(visited, 0, sizeof(visited));
    }
    cout << result;
    return 0;
}
