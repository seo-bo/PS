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
	int n = 0, color = 1, ans = INT_MAX;
	cin >> n;
	vector<vector<int>>grid(n, vector<int>(n));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (auto& i : grid)
	{
		for (auto& j : i)
		{
			int temp = 0;
			cin >> temp;
			if (temp)
			{
				j = -1;
			}
		}
	}
	auto bfs = [&](int x, int y, int c)
		{
			queue<pii>q;
			q.push(make_pair(x, y));
			grid[x][y] = c;
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (0 <= nx && nx < n && 0 <= ny && ny < n)
					{
						if (grid[nx][ny] == -1)
						{
							grid[nx][ny] = c;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		};
	auto brid = [&](int x, int y)
		{
			vector<vector<bool>>visited(n, vector<bool>(n, false));
			visited[x][y] = true;
			queue<tuple<int, int, int>>q;
			q.push(make_tuple(x, y, 0));
			while (!q.empty())
			{
				auto [a, b, c] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny])
					{
						visited[nx][ny] = true;
						if (grid[nx][ny] == grid[x][y])
						{
							q.push(make_tuple(nx, ny, c));
						}
						else
						{
							if (!grid[nx][ny])
							{
								q.push(make_tuple(nx, ny, c + 1));
							}
							else
							{
								return c;
							}
						}
					}
				}
			}
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == -1)
			{
				bfs(i, j, color++);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j])
			{
				bool check = false;
				for (int z = 0; z < 4; ++z)
				{
					int nx = i + dir[z][0];
					int ny = j + dir[z][1];
					if (0 <= nx && nx < n && 0 <= ny && ny < n && !grid[nx][ny])
					{
						check = true;
						break;
					}
				}
				if (check)
				{
					ans = min(ans, brid(i, j));
				}
			}
		}
	}
	cout << ans;
	return 0;
}