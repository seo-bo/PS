#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0;
	cin >> n >> x;
	int pivot = x * 5;
	vector<vector<int>>graph(pivot + 1, vector<int>(pivot + 1, INT_MAX));
	for (int i = 1; i <= pivot; ++i)
	{
		graph[i][i] = 0;
	}
	vector<vector<int>>v(n + 1, vector<int>(6, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			cin >> v[i][j];
			v[i][j] = (j - 1) * x + v[i][j];
		}
		for (int j = 1; j <= 5; ++j)
		{
			for (int k = 1; k <= 5; ++k)
			{
				if (j == k)
				{
					continue;
				}
				graph[v[i][j]][v[i][k]] = 1;
			}
		}
	}
	for (int i = 1; i <= pivot; ++i)
	{
		for (int j = 1; j <= pivot; ++j)
		{
			for (int k = 1; k <= pivot; ++k)
			{
				if (graph[j][i] != INT_MAX && graph[i][k] != INT_MAX)
				{
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0, ans = INT_MAX;
		cin >> a >> b;
		for (int i = 1; i <= 5; ++i)
		{
			for (int j = 1; j <= 5; ++j)
			{
				if (graph[v[a][i]][v[b][j]] == INT_MAX)
				{
					continue;
				}
				ans = min(ans, graph[v[a][i]][v[b][j]] + 1);
			}
		}
		cout << ((ans == INT_MAX) ? -1 : ans) << '\n';
	}
	return 0;
}