#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<int>graph[1001 * 1001];
int degree[1001 * 1001] = { 0 };
int grid[1001][1001] = { 0, };
int N = 0;

void topo_sort()
{
	priority_queue<int, vector<int>>q;
	int cnt = N * N;
	for (int i = 1; i <= N * N; ++i)
	{
		if (!degree[i])
		{
			q.push(i);
			grid[(i - 1) / N + 1][(i - 1) % N + 1] = cnt--;
		}
	}
	while (!q.empty())
	{
		int cur = q.top();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (!(--degree[i]))
			{
				q.push(i);
				grid[(i - 1) / N + 1][(i - 1) % N + 1] = cnt--;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	char temp;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N - 1; ++j)
		{
			cin >> temp;
			if (temp == '<')
			{
				graph[(i - 1) * N + j + 1].push_back((i - 1) * N + j);
				degree[(i - 1) * N + j]++;
			}
			else
			{
				graph[(i - 1) * N + j].push_back((i - 1) * N + j + 1);
				degree[(i - 1) * N + j + 1]++;
			}
		}
	}
	for (int i = 1; i <= N * (N - 1); ++i)
	{
		cin >> temp;
		if (temp == '<')
		{
			graph[i + N].push_back(i);
			degree[i]++;
		}
		else
		{
			graph[i].push_back(i + N);
			degree[i + N]++;
		}
	}
	topo_sort();
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}