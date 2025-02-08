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
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int>parent(k + 1, INT_MAX);
	unordered_map<int, pii>mm;
	unordered_set<int>comp;
	vector<vector<int>>grid(n, vector<int>(m, 0));
	for (int i = 1; i <= k; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		mm[i] = make_pair(--a, --b);
		grid[a][b] = i;
	}
	vector<vector<int>>visited(n, vector<int>(m, 0));
	vector<vector<int>>dir = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	int s = 0;
	cin >> s;
	comp.insert(s);
	auto [_, __] = mm[s];
	queue<pii>q;
	visited[_][__] = 1;
	q.push(make_pair(_, __));
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nx = a + dir[i][0];
			int ny = b + dir[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny])
			{
				if (!visited[nx][ny])
				{
					visited[nx][ny] = visited[a][b] + 1;
					comp.insert(grid[nx][ny]);
					parent[grid[nx][ny]] = grid[a][b];
					q.push(make_pair(nx, ny));
				}
				else if (visited[nx][ny] == visited[a][b] + 1)
				{
					parent[grid[nx][ny]] = min(parent[grid[nx][ny]], grid[a][b]);
				}
			}
		}
	}
	if (comp.size() != k)
	{
		cout << -1;
		return 0;
	};
	vector<ll>ans(k + 1, 0);
	vector<vector<int>>graph(k + 1);
	vector<bool>vis(k + 1, false);
	for (int i = 1; i <= k; ++i)
	{
		if (parent[i] != INT_MAX)
		{
			graph[i].push_back(parent[i]);
			graph[parent[i]].push_back(i);
		}
	}
	function<ll(int)> dfs = [&](int node) -> ll
		{
			ans[node] = 1;
			for (auto& i : graph[node])
			{
				if (!vis[i])
				{
					vis[i] = true;
					ans[node] += dfs(i);
				}
			}
			return ans[node];
		};
	vis[s] = true;
	dfs(s);
	for (int i = 1; i <= k; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}