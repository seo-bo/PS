#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<int>degree(n + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	vector<int>ans(n + 1, 0);
	{
		queue<int>q;
		for (int i = 1; i <= n; ++i)
		{
			if (degree[i] == 1)
			{
				q.push(i);
				ans[i] = INT_MAX;
			}
		}
		while (!q.empty())
		{
			int a = q.front();
			q.pop();
			for (auto& i : graph[a])
			{
				if (--degree[i] == 1)
				{
					ans[i] = INT_MAX;
					q.push(i);
				}
			}
		}
	}
	queue<pii>q;
	for (int i = 1; i <= n; ++i)
	{
		if (!ans[i])
		{
			q.push(make_pair(0, i));
		}
	}
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		for (auto& i : graph[b])
		{
			if (ans[i] == INT_MAX)
			{
				ans[i] = a + 1;
				q.push(make_pair(a + 1, i));
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
