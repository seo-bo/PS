#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<int>degree(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		if (++degree[a] > 2)
		{
			cout << "No";
			return 0;
		}
		if (++degree[b] > 2)
		{
			cout << "No";
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] < 2)
		{
			cout << "No";
			return 0;
		}
	}
	vector<bool>visited(n + 1, false);
	queue<int>q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto& i : graph[a])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			cout << "No";
			return 0;
		}
	}
	if (n != m)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
	return 0;
}
