#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<bool>visited(n + 1, 0);
	for (int i = 0; i < n - 1; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	function<void(int, int)>dfs = [&](int depth, int start) ->void
		{
			if (graph[start].size() == 1 && start != 1)
			{
				if (depth % 2)
				{
					ans += depth;
				}
				return;
			}
			for (auto& i : graph[start])
			{
				if (!visited[i])
				{
					visited[i] = true;
					dfs(depth + 1, i);
				}
			}
		};
	visited[1] = true;
	dfs(0, 1);
	if (ans % 2)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}