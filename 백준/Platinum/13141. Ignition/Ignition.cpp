#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1, vector<int>(n + 1, -1));
	vector<vector<int>>dist(n + 1, vector<int>(n + 1, INT_MAX));
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
		graph[a][b] = graph[b][a] = max(graph[a][b], c);
	}
	for (int k = 1; k <= n; ++k)
	{
		dist[k][k] = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				if (graph[j][k] != -1)
				{
					temp = max(temp, (dist[i][j] + dist[i][k] + graph[j][k]) * 10 / 2);
				}
			}
		}
		ans = min(ans, temp);
	}
	cout << ans / 10 << '.' << ans % 10;
	return 0;
}