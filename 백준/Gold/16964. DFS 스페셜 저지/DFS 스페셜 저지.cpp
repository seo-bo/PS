#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<int>v(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		v[a] = i;
	}
	if (v[1])
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), [&](const int& a, const int& b)
			{
				return v[a] < v[b];
			});
	}
	vector<bool>visited(n + 1, false);
	visited[1] = true;
	int idx = 1;
	function<void(int)> dfs = [&](int node)
		{
			for (auto& i : graph[node])
			{
				if (visited[i])
				{
					continue;
				}
				if (v[i] == idx)
				{
					visited[i] = true;
					idx++;
					dfs(i);
				}
				else
				{
					cout << 0;
					exit(0);
				}
			}
		};
	dfs(1);
	cout << 1;
	return 0;
}