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
	int n = 0, m = 0, ans = INT_MAX, empty = 0;
	cin >> n >> m;
	vector<vector<int>>grid(n, vector<int>(n));
	vector<pii>virus;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 0)
			{
				empty++;
			}
			else if (grid[i][j] == 2)
			{
				virus.push_back(make_pair(i, j));
			}
		}
	}
	if (empty == 0) 
	{
		cout << 0;
		return 0;
	}
	vector<vector<int>>visited(n, vector<int>(n, -1));
	auto bfs = [&](queue<pii>& q)
		{
			int e = empty;
			int mm = 0;
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						if (visited[nx][ny] == -1)
						{
							if (grid[nx][ny] == 0)
							{
								visited[nx][ny] = visited[a][b] + 1;
								mm = max(visited[nx][ny], mm);
								e--;
								q.push(make_pair(nx, ny));
							}
							else if (grid[nx][ny] == 2)
							{
								visited[nx][ny] = visited[a][b] + 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
			if (!e)
			{
				ans = min(ans, mm);
			}
		};

	vector<pii>temp;
	function<void(int, int, int)> dfs = [&](int depth, int mask, int start) ->void
		{
			if (depth == m)
			{
				queue<pii>q;
				for (auto& i : temp)
				{
					visited[i.first][i.second] = 0;
					q.push(i);
				}
				bfs(q);
				vector<vector<int>>(n, vector<int>(n, -1)).swap(visited);
				return;
			}
			for (int i = start; i < virus.size(); ++i)
			{
				if (!(mask & (1 << i)))
				{
					mask |= (1 << i);
					temp.push_back(virus[i]);
					dfs(depth + 1, mask, i + 1);
					temp.pop_back();
					mask &= ~(1 << i);
				}
			}
		};
	dfs(0, 0, 0);
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}