#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, r = 0, cnt = 1;
	cin >> n >> m >> r;
	vector<vector<int>>graph(n + 1);
	vector<int>visited(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (auto& i : graph)
	{
		sort(i.begin(), i.end());
	}
	visited[r] = cnt;
	queue<int>q;
	q.push(r);
	cnt++;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (!visited[i])
			{
				visited[i] = cnt;
				q.push(i);
				cnt++;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << visited[i] << '\n';
	}
	return 0;
}