#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<bool>>graph(n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = true;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = true;
	}
	vector<int>ans;
	while (1)
	{
		vector<vector<bool>>temp = graph;
		int res = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				for (int k = 1; k <= n; ++k) // k -> i -> j ?
				{
					if (!graph[k][i] || !graph[i][j] || temp[k][j])
					{
						continue;
					}
					temp[k][j] = true;
					temp[j][k] = true;
					res++;
				}
			}
		}
		if (!res)
		{
			cout << ans.size() << '\n';
			for (auto& i : ans)
			{
				cout << i << '\n';
			}
			break;
		}
		ans.push_back(res);
		graph = move(temp);
	}
	return 0;
}