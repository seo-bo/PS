#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<bool>visited(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	function<void(int)> dfs = [&](int start) ->void
		{
			for (auto& i : graph[start])
			{
				if (!visited[i])
				{
					visited[i] = true;
					dfs(i);
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}