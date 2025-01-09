#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<ti>v(m + 1), query(q);
	vector<bool>visited(m + 1, false);
	for (int i = 1; i <= m; ++i)
	{
		auto& [a, b, c] = v[i];
		cin >> a >> b >> c;
	}
	for (auto& [a, b, c] : query)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			c = 0;
			visited[b] = true;
		}
		else
		{
			cin >> b >> c;
		}
	}
	vector<vector<ll>>graph(n + 1, vector<ll>(n + 1, LLONG_MAX));
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i)
	{
		if (!visited[i])
		{
			auto& [a, b, c] = v[i];
			graph[a][b] = min(graph[a][b], c);
			graph[b][a] = graph[a][b];
		}
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][k] != LLONG_MAX && graph[k][j] != LLONG_MAX && graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	vector<ll>ans;
	auto sv = [&](ll v1, ll v2)
		{
			auto& [a, b, c] = v[v1];
			if (c >= graph[a][b])
			{
				return;
			}
			graph[a][b] = min(graph[a][b], c);
			graph[b][a] = graph[a][b];
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					if (graph[i][a] != LLONG_MAX && graph[b][j] != LLONG_MAX && graph[i][j] > graph[i][a] + graph[b][j] + c)
					{
						graph[i][j] = graph[i][a] + graph[b][j] + c;
					}
					if (graph[i][b] != LLONG_MAX && graph[a][j] != LLONG_MAX && graph[i][j] > graph[i][b] + graph[a][j] + c)
					{
						graph[i][j] = graph[i][b] + graph[a][j] + c;
					}
				}
			}
		};
	for (int i = q - 1; i >= 0; --i)
	{
		auto& [num, v1, v2] = query[i];
		if (num == 1)
		{
			sv(v1, v2);
		}
		else
		{
			ans.push_back((graph[v1][v2] == LLONG_MAX) ? -1 : graph[v1][v2]);
		}
	}
	int len = ans.size();
	for (int i = len - 1; i >= 0; --i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
