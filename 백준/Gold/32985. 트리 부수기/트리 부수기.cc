#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n);
	vector<int>visited(n, -1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int>q;
	visited[0] = 0;
	q.push(0);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (visited[i] == -1)
			{
				visited[i] = visited[cur] + 1;
				q.push(i);
			}
		}
	}
	for (int i = n - 1; i >= 1; --i)
	{
		if (n % 2)
		{
			cout << ((visited[i] % 2) ? 1 : 0);
		}
		else
		{
			cout << ((visited[i] % 2) ? 0 : 1);
		}
	}
	return 0;
}