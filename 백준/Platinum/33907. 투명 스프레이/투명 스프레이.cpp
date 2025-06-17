#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	auto bfs = [&](ll mid)
		{
			vector<vector<int>>visited(n + 1, vector<int>(m + 1, INT_MAX));
			visited[1][1] = 0;
			deque<pii>dq;
			dq.push_back(make_pair(1, 1));
			while (!dq.empty())
			{
				auto [x, y] = dq.front();
				dq.pop_front();
				if (x == n && y == m)
				{
					return visited[x][y] <= k;
				}
				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
					{
						int cost = (v[nx][ny] > mid);
						if (visited[nx][ny] > visited[x][y] + cost)
						{
							visited[nx][ny] = visited[x][y] + cost;
							if (cost)
							{
								dq.push_back(make_pair(nx, ny));
							}
							else
							{
								dq.push_front(make_pair(nx, ny));
							}
						}
					}
				}
			}
			return false;
		};
	ll left = 0, right = INT_MAX, ans = -1;
	while (left <= right)
	{
		ll mid = (left + right) >> 1;
		if (bfs(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}