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
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<int>>grid(n, vector<int>(m, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			if (str[j] == 'L')
			{
				grid[i][j] = 1;
			}
			else
			{
				grid[i][j] = 0;
			}
		}
	}
	auto bfs = [&](int x, int y)
		{
			vector<vector<bool>>visited(n, vector<bool>(m, false));
			visited[x][y] = true;
			queue<tuple<int, int, int>>q;
			q.push(make_tuple(x, y, 0));
			while (!q.empty())
			{
				auto [a, b, c] = q.front();
				q.pop();
				ans = max(ans, c);
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny])
					{
						visited[nx][ny] = true;
						q.push(make_tuple(nx, ny, c + 1));
					}
				}
			}
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}