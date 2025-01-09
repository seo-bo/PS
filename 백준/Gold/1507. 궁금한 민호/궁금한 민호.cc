#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n, vector<int>(n, 0));
	for (auto& i : graph)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<int>>v = graph;
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j || i == k || k == j)
				{
					continue;
				}
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					cout << -1;
					return 0;
				}
				if (graph[i][j] == graph[i][k] + graph[k][j])
				{
					v[i][j] = 0;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ans += v[i][j];
		}
	}
	cout << ans / 2;
	return 0;
}