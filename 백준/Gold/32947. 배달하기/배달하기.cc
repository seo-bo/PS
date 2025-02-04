#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, s = 0, e = 0, k = 0;
	cin >> n >> m >> s >> e >> k;
	vector<int>ow(k);
	for (auto& i : ow)
	{
		cin >> i;
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<ll>visited(n + 1, INT_MAX);
	queue<pll>q;
	q.push(make_pair(0, s));
	while (!q.empty())
	{
		auto [cost, ver] = q.front();
		q.pop();
		if (ow[cost % k] == ver)
		{
			if (cost <= visited[ver] + k + 5)
			{
				q.push(make_pair(cost + 1, ver));
			}
			continue;
		}
		if (ver == e)
		{
			cout << cost;
			return 0;
		}
		for (auto& i : graph[ver])
		{
			if (visited[i] == INT_MAX)
			{
				visited[i] = cost + 1;
				q.push(make_pair(visited[i], i));
			}
		}
	}
	cout << -1;
	return 0;
}