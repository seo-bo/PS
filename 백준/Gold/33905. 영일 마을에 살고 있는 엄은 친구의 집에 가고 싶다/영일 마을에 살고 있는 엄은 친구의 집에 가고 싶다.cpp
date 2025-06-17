#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	n++;
	vector<vector<int>>graph(n + 1);
	vector<bool>ban(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < k; ++i)
	{
		int a = 0;
		cin >> a;
		ban[a] = true;
	}
	queue<int>q;
	q.push(1);
	vector<int>visited(n + 1, INT_MAX);
	visited[1] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (ban[i])
			{
				continue;
			}
			if (visited[i] > visited[cur] + 1)
			{
				visited[i] = visited[cur] + 1;
				q.push(i);
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (visited[i] != INT_MAX)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}