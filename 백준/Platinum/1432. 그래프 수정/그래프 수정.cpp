#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>graph[51];
int degree[10001], result[10001] = { 0, };
int visited = 0;

void topo_sort(int vertex)
{
	int temp = vertex;
	priority_queue<int, vector<int>>pq;
	for (int i = 1; i <= temp; ++i)
	{
		if (!degree[i])
		{
			pq.push(i);
		}
	}
	while (!pq.empty())
	{
		int current = pq.top();
		result[current] = temp; // 인덱스에 맞춰 최후방값부터
		temp--;
		visited++;
		pq.pop();
		for (auto& i : graph[current])
		{
			if (!(--degree[i]))
			{
				pq.push(i);
			}
		}
	}
	if (visited != vertex)
	{
		cout << "-1";
		exit(0);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int vertex = 0;
	cin >> vertex;
	for (int i = 1; i <= vertex; ++i)
	{
		string temp;
		cin >> temp;
		int size = temp.length();
		for (int j = 0; j < size; ++j)
		{
			if (temp[j] == '1')
			{
				graph[j + 1].push_back(i); // 역방향 간선 삽입
				degree[i]++; // in_degree가 아니라 out_degree
			}
		}
	}
	topo_sort(vertex);
	for (int i = 1; i <= vertex; ++i)
	{
		cout << result[i] << " ";
	}
	return 0;
}