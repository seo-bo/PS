#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) // A ~ E 5명?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<bool>visited(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bool check = false;
	function<void(int, int)> dfs = [&](int depth, int node)
		{
			if (depth == 4)
			{
				check = true;
				return;
			}
			for (auto i : graph[node])
			{
				if (!visited[i] && !check)
				{
					visited[i] = true;
					dfs(depth + 1, i);
					visited[i] = false;
				}
			}
		};
	for (int i = 0; i <= n; ++i)
	{
		if (check)
		{
			cout << 1;
			return 0;
		}
		if (!visited[i])
		{
			visited[i] = true;
			dfs(0, i);
			visited[i] = false;
		}
	}
	cout << 0;
	return 0;
}