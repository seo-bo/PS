#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1, vector<ll>(n + 1, INF));
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][k] != INF && graph[k][j] != INF)
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (graph[i][j] == INF)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << graph[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}