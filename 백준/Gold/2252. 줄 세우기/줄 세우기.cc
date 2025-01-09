#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vertex = 0, edge = 0;
vector<int>graph[32004];
vector<int>result;
int degree[32004] = { 0, };

void topo_sort()
{
	queue<int>q;
	for (int i = 1; i <= vertex; ++i)
	{
		if (!degree[i])
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		result.push_back(current);
		for (auto& i : graph[current])
		{
			if (!(--degree[i]))
			{
				q.push(i);
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