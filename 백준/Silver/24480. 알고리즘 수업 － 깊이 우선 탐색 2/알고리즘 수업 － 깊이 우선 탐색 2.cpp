#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, r = 0;
	cin >> n >> m >> r;
	vector<vector<int>>graph(n + 1);
	vector<bool>visited(n + 1,false);
	vector<int>ans(n + 1, 0);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (auto& i : graph)
	{
		if (!i.empty())
		{
			sort(i.begin(), i.end(), [&](const int& a, const int& b)
				{
					return a > b;
				});
		}
	}
	ans[r] = 1;
	visited[r] = true;
	int cnt = 2;
	function<void(int)> dfs = [&](int start) ->void
		{
			for (auto& i : graph[start])
			{
				if (!visited[i])
				{
					visited[i] = true;
					ans[i] = cnt++;
					dfs(i);
				}
			}
		};
	dfs(r);
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}