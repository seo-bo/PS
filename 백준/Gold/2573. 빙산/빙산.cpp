#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	auto bfs = [&](int x, int y)
		{
			queue<pii>q;
			q.push(make_pair(x, y));
			visited[x][y] = true;
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] && !visited[nx][ny])
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		};
	int K = 0;
	while (1)
	{		
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (!visited[i][j] && grid[i][j])
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (!cnt)
		{
			cout << 0;
			return 0;
		}
		else if (cnt >= 2)
		{
			cout << K;
			return 0;
		}
		vector<ti>temp;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j])
				{
					int cc = 0;
					for (int k = 0; k < 4; ++k)
					{
						int nx = i + dir[k][0];
						int ny = j + dir[k][1];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m)
						{
							if (!grid[nx][ny])
							{
								cc++;
							}
						}
					}
					temp.push_back(make_tuple(i, j, max(0, grid[i][j] - cc)));
				}
			}
		}
		for (auto& [i, j, w] : temp)
		{
			grid[i][j] = w;
		}
		vector<vector<bool>>(n, vector<bool>(m, false)).swap(visited);
		K++;
	}
	return 0;
}