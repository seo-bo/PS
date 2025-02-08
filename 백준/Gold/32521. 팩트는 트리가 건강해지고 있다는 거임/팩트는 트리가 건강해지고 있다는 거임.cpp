#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>graph(n + 1);
	vector<int>hel(n + 1, 0);
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		cin >> hel[i];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	visited[1] = true;
	int ans = 0;
	function<int(int)> dfs = [&](int node) // 이런; 이진 트리가 아니였네요;;;;;;
		{
			int cost = hel[node];
			vector<int>temp;
			for (auto& i : graph[node])
			{
				if (!visited[i])
				{
					visited[i] = true;
					temp.push_back(dfs(i));
				}
			}
			sort(temp.begin(), temp.end());
			for (int i = 0; i < temp.size(); ++i)
			{
				int np = cost + temp[i];
				if (np > k)
				{
					ans += temp.size() - i;
					break;
				}
				cost = np;
			}
			return cost;
		};
	dfs(1);
	cout << ans;
	return 0;
}