#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int degree[32001] = { 0, };
vector<int>graph[32001];
vector<int>result;
int vertex = 0, edge = 0;

void topo_sort()
{
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 1; i <= vertex; ++i)
	{
		if (!degree[i])
		{
			pq.push(i);
		}
	}
	while (!pq.empty())
	{
		int current = pq.top();
		pq.pop();
		result.push_back(current);
		for (auto& i : graph[current])
		{
			if (!(--degree[i]))
			{
				pq.push(i);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> vertex >> edge;
	for (int i = 1; i <= edge; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		degree[end]++;
	}
	topo_sort();
	for (auto& i : result)
	{
		cout << i << " ";
	}
	return 0;
}