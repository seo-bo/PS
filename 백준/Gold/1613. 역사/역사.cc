#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>graph(n + 1, vector<int>(n + 1, INT_MAX));
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = 0;
	}
	for (int i = 0; i < k; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	for (int c = 1; c <= n; ++c)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][c] != INT_MAX && graph[c][j] != INT_MAX && graph[i][j] > graph[i][c] + graph[c][j])
				{
					graph[i][j] = graph[i][c] + graph[c][j];
				}
			}
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (graph[a][b] != INT_MAX)
		{
			cout << -1 << '\n';
		}
		else if (graph[b][a] != INT_MAX)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	return 0;
}