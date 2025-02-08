#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>>rgraph(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a][b] = 1;
		rgraph[b][a] = 1;
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][k] && graph[k][j])
				{
					graph[i][j] = 1;
				}
				if (rgraph[i][k] && rgraph[k][j])
				{
					rgraph[i][j] = 1;
				}
			}
		}
	}
	int mid = (n + 1) / 2, ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int h = 0, l = 0;
		for (int j = 1; j <= n; ++j)
		{
			h += graph[i][j];
			l += rgraph[i][j];
		}
		if (h >= mid || l >= mid)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}