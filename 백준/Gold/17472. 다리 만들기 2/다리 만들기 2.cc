#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, color = 1;
	cin >> n >> m;
	vector<vector<int>>grid(n + 1, vector<int>(m + 1, 0));
	vector<vector<bool>>visited(n + 1, vector<bool>(m + 1, false));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>>pq;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	auto bfs = [&](int x, int y)
		{
			grid[x][y] = color;
			visited[x][y] = true;
			queue<pii>q;
			q.push(make_pair(x, y));
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
					{
						if (!visited[nx][ny] && grid[nx][ny])
						{
							visited[nx][ny] = true;
							grid[nx][ny] = color;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		};
	auto bfs2 = [&](int x, int y, int pivot)
		{
			queue<tuple<int, int, int, int>>q; // x, y, 횟수, 방향
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
				{
					if (!grid[nx][ny])
					{
						q.push(make_tuple(nx, ny, 1, i));
					}
				}
			}
			while (!q.empty())
			{
				auto [a, b, c, d] = q.front();
				q.pop();
				int nx = a + dir[d][0];
				int ny = b + dir[d][1];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
				{
					if (!grid[nx][ny]) // 바다일때
					{
						q.push(make_tuple(nx, ny, c + 1, d));
					}
					else
					{
						if (grid[nx][ny] != pivot) // 새로운 섬을 만났을때
						{
							if (c >= 2) // 다리 길이를 충족하면
							{
								pq.push(make_tuple(-c, pivot, grid[nx][ny]));
							}
						}
					}
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (!visited[i][j] && grid[i][j])
			{
				bfs(i, j);
				color++;
			}
		}
	}
	vector<int>parent(color, 0);
	vector<int>rank(color, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root) ->int
		{
			if (parent[root] != root)
			{
				return parent[root] = find(parent[root]);
			}
			return parent[root];
		};
	auto merge = [&](int root1, int root2)
		{
			int r1 = find(root1);
			int r2 = find(root2);
			if (r1 != r2)
			{
				if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
				}
				else if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
				}
				else
				{
					parent[r2] = r1;
					rank[r1]++;
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (grid[i][j])
			{
				bfs2(i, j, grid[i][j]);
			}
		}
	}
	int ans = 0, e = 0;
	while (!pq.empty() && e < color - 2)
	{
		auto [a, b, c] = pq.top();
		pq.pop();
		int r1 = find(b), r2 = find(c);
		if (r1 != r2)
		{
			merge(b, c);
			ans += -a;
			e++;
		}
	}
	if (e < color - 2)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}