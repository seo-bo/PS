#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x1 = 0, x2 = 0;
	cin >> n >> x1 >> x2;
	if (x1 == x2)
	{
		cout << 0;
		return 0;
	}
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	vector<bool>visited(n + 1, false);
	visited[x1] = true;
	function<void(int, int, int)> dfs = [&](int node, int sum, int p)
		{
			if (node == x2)
			{
				cout << sum - p;
				exit(0);
			}
			for (auto& [a, b] : graph[node])
			{
				if (!visited[a])
				{
					visited[a] = true;
					dfs(a, sum + b, max(p, b));
				}
			}
		};
	dfs(x1, 0, 0);
	return 0;
}