#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		graph[temp].push_back(i);
		graph[i].push_back(temp);
	}
	vector<int>visited(n + 1, INT_MAX);
	visited[1] = 0;
	queue<int>q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (visited[i] > visited[cur] + 1)
			{
				visited[i] = visited[cur] + 1;
				q.push(i);
			}
		}
	}
	vector<int>res(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i] == INT_MAX)
		{
			visited[i] = 0;
			continue;
		}
		res[visited[i]]++;
	}
	ll ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		ll pivot = 0;
		for (int j = 0; j <= n; j += i)
		{
			pivot += res[j];
		}
		ans = max(ans, pivot);
	}
	cout << ans;
	return 0;
}