#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, ans = 0;
		cin >> n >> m;
		vector<vector<pii>>graph(n + 1);
		vector<bool>visited(n + 1, false);
		visited[1] = true;
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));
		}
		function<int(int)> dfs = [&](int node) -> int
			{
				visited[node] = true;
				if (graph[node].size() == 1)
				{
					return graph[node].front().second;
				}
				int sum = 0;
				for (auto& i : graph[node])
				{
					if (!visited[i.first])
					{
						sum += min(i.second, dfs(i.first));
					}
				}
				return sum;
			};
		for (auto& i : graph[1])
		{
			ans += min(i.second, dfs(i.first));
		}
		cout << ans << '\n';
	}
	return 0;
}