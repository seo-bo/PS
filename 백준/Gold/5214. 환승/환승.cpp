#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void) // 가상 노드를 만들까...
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, m = 0;
	cin >> n >> k >> m;
	vector<vector<int>>graph(n + m + 1);
	for (int i = 0; i < m; ++i)
	{
		int node = n + i + 1;
		for (int i = 0; i < k; ++i)
		{
			int temp = 0;
			cin >> temp;
			graph[temp].push_back(node);
			graph[node].push_back(temp);
		}
	}
	vector<bool>visited(n + m + 1, false);
	queue<pii>q;
	q.push(make_pair(1, 1));
	visited[1] = true;
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		if (a == n)
		{
			cout << b;
			return 0;
		}
		for (auto& i : graph[a])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(make_pair(i, b + (i <= n)));
			}
		}
	}
	cout << -1;
	return 0;
}