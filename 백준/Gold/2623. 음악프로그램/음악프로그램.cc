#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>graph[1001];
vector<int>result;
int ary[101][1001] = { 0, };
int degree[1001] = { 0, };
int vertex = 0, test = 0;

void topo_sort()
{
	int count = 0;
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
		count++;
		for (auto& i : graph[current])
		{
			if (!(--degree[i]))
			{
				q.push(i);
			}
		}
	}
	if (vertex != count)
	{
		cout << 0;
		exit(0);
	}
	for (auto& i : result)
	{
		cout << i << "\n";
	}
	exit(0);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> vertex >> test;
	for (int i = 1; i <= test; ++i)
	{
		int temp = 0;
		cin >> temp;
		for (int k = 1; k <= temp; ++k)
		{
			cin >> ary[i][k];
		}
		for (int j = 1; j <= temp; ++j)
		{
			for (int k = j + 1; k <= temp; ++k)
			{
				graph[ary[i][j]].push_back(ary[i][k]);
				degree[ary[i][k]]++;
			}
		}
	}
	topo_sort();
	return 0;
}