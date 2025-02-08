#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<int>degree(n + 1, 0);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	int idx = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] != 1 && degree[i] != 3)
		{
			cout << -1;
			return 0;
		}
		if (degree[i] == 1)
		{
			idx = i;
		}
	}
	auto bfs = [&](int node)
		{
			vector<int>dist(n + 1, -1);
			dist[node] = 0;
			queue<int>q;
			q.push(node);
			int pivot = node;
			while (!q.empty())
			{
				int a = q.front();
				q.pop();
				for (auto& i : graph[a])
				{
					if (dist[i] == -1)
					{
						dist[i] = dist[a] + 1;
						q.push(i);
						if (dist[i] > dist[pivot])
						{
							pivot = i;
						}
					}
				}
			}
			return make_pair(pivot, dist[pivot]);
		};
	auto [a, aa] = bfs(idx);
	auto [b, bb] = bfs(a);
	vector<int>dist(n + 1, -1), par(n + 1, -1);
	auto c1 = [&](int node)
		{
			dist[node] = 0;
			queue<int>q;
			q.push(node);
			while (!q.empty())
			{
				int a = q.front();
				q.pop();
				for (auto& i : graph[a])
				{
					if (dist[i] == -1)
					{
						dist[i] = dist[a] + 1;
						par[i] = a;
						q.push(i);
					}
				}
			}
		};
	c1(a);
	deque<int>dq;
	int x = b;
	while (x != -1)
	{
		dq.push_front(x);
		x = par[x];
	}
	int len = dq.size();
	vector<int>temp;
	int p1 = dq[len / 2], p2 = dq[len / 2 - 1], p3 = dq[len / 2 + 1];
	if (degree[p1] == 3)
	{
		temp.push_back(p1);
	}
	if (degree[p2] == 3)
	{
		temp.push_back(p2);
	}
	if (degree[p3] == 3)
	{
		temp.push_back(p3);
	}
	auto check = [&](int node)
		{
			vector<int>dis(n + 1, -1);
			dis[node] = 0;
			queue<int>q;
			q.push(node);
			while (!q.empty())
			{
				int a = q.front();
				q.pop();
				for (auto& i : graph[a])
				{
					if (dis[i] == -1)
					{
						dis[i] = dis[a] + 1;
						q.push(i);
					}
				}
			}
			int pi = -1;
			for (int i = 1; i <= n; ++i)
			{
				if (degree[i] == 1 && i != node)
				{
					if (pi == -1)
					{
						pi = dis[i];
					}
					else if (pi != dis[i])
					{
						return false;
					}
				}
			}
			return true;
		};
	vector<int>ans;
	for (auto& i : temp)
	{
		if (check(i))
		{
			ans.push_back(i);
		}
	}
	if (ans.empty())
	{
		cout << -1;
		return 0;
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}