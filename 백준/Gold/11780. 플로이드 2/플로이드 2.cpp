#include <bits/stdc++.h>
#include <unordered_set>
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1, vector<ll>(n + 1, INF));
	vector<vector<ll>>v(n + 1, vector<ll>(n + 1, -1));
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (c < graph[a][b])
		{
			graph[a][b] = c;
			v[a][b] = b;
		}
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][k] != INF && graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
					v[i][j] = v[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (graph[i][j] == INF || i == j)
			{
				cout << 0 << '\n';
				continue;
			}
			vector<ll>temp;
			ll cur = i;
			while (cur != j)
			{
				temp.push_back(cur);
				cur = v[cur][j];
			}
			temp.push_back(j);
			cout << temp.size() << ' ';
			for (auto& k : temp)
			{
				cout << k << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}