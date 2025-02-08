#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<vector<pii>>graph(n + 1);
	vector<bool>visited(n + 1, false);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	function<int(int)> dfs = [&](int root) ->int
		{
			visited[root] = true;
			if (graph[root].size() == 1) // leaf
			{
				return graph[root].front().second;
			}
			int sum = 0;
			for (auto& i : graph[root])
			{
				if (!visited[i.first])
				{
					sum += min(i.second, dfs(i.first));
				}
			}
			return sum;
		};
	visited[1] = true;
	for (auto& i : graph[1])
	{
		ans += min(i.second, dfs(i.first));
	}
	cout << ans;
	return 0;
}