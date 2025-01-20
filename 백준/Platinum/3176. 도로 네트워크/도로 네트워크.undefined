#include <bits/stdc++.h>
#define P 19
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>depth(n + 1, 0);
	vector<vector<int>>table(P, vector<int>(n + 1, 0)), mini(P, vector<int>(n + 1, INT_MAX)), maxi(P, vector<int>(n + 1, -1));
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	function<void(int, int, int)> dfs = [&](int parent, int node, int lv)
		{
			table[0][node] = parent;
			depth[node] = lv;
			for (auto& [a, b] : graph[node])
			{
				if (a == parent)
				{
					continue;
				}
				mini[0][a] = b;
				maxi[0][a] = b;
				dfs(node, a, lv + 1);
			}
		};
	dfs(0, 1, 0);
	for (int i = 1; i < P; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int mid = table[i - 1][j];
			table[i][j] = table[i - 1][mid];
			maxi[i][j] = max(maxi[i - 1][j], maxi[i - 1][mid]);
			mini[i][j] = min(mini[i - 1][j], mini[i - 1][mid]);
		}
	}
	auto cal = [&](int a, int b)
		{
			if (depth[a] < depth[b])
			{
				swap(a, b);
			}
			int diff = depth[a] - depth[b];
			int mi = INT_MAX, ma = -1;
			for (int i = 0; diff; ++i)
			{
				if (diff & 1)
				{
					mi = min(mi, mini[i][a]);
					ma = max(ma, maxi[i][a]);
					a = table[i][a];
				}
				diff >>= 1;
			}
			if (a == b)
			{
				return make_pair(mi, ma);
			}
			for (int i = P - 1; i >= 0; --i)
			{
				if (table[i][a] != table[i][b])
				{
					mi = min({ mi,mini[i][a],mini[i][b] });
					ma = max({ ma,maxi[i][a],maxi[i][b] });
					a = table[i][a];
					b = table[i][b];
				}
			}
			mi = min({ mi,mini[0][a],mini[0][b] });
			ma = max({ ma,maxi[0][a],maxi[0][b] });
			return make_pair(mi, ma);
		};
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		pii ans = cal(a, b);
		cout << ans.first << ' ' << ans.second << '\n';
	}
	return 0;
}
