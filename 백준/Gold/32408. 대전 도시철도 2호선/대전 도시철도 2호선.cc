#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>parent(n + 1, -1);
	queue<int>q;
	q.push(1);
	parent[1] = 0;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto& i : graph[a])
		{
			if (parent[i] == -1)
			{
				parent[i] = a;
				q.push(i);
				if (i == n)
				{
					break;
				}
			}
		}
	}
	deque<int>v;
	vector<bool>in(n + 1, false), visited(n + 1, false);
	int cur = n;
	while (cur != 0)
	{
		v.push_front(cur);
		in[cur] = visited[cur] = true;
		cur = parent[cur];
	}
	ll ans = 0;
	function<ll(int)> sub = [&](int node)
		{
			ll cost = 1;
			for (auto& i : graph[node])
			{
				if (!in[i] && !visited[i])
				{
					visited[i] = true;
					cost += sub(i);
				}
			}
			return cost;
		};
	for (auto& i : v)
	{
		for (auto& j : graph[i])
		{
			if (!in[j] && !visited[j])
			{
				visited[j] = true;
				ll pivot = sub(j);
				ans += pivot * (pivot - 1LL) / 2LL;
			}
		}
	}
	ll p = n - v.size();
	cout << p * (p - 1LL) / 2LL - ans;
	return 0;
}