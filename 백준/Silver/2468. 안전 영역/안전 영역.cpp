#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, ans = 0, maxi = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
			maxi = max(maxi, j);
		}
	}
	auto bfs = [&](int x, int y, int k)
		{
			visited[x][y] = true;
			queue<pii>q;
			q.push(make_pair(x, y));
			while (!q.empty())
			{
				pii cur = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = cur.first + dir[i][0];
					int ny = cur.second + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						if (!visited[nx][ny] && v[nx][ny] > k)
						{
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		};
	for (int k = 0; k <= maxi; ++k)
	{
		int temp = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!visited[i][j] && v[i][j] > k)
				{
					temp++;
					bfs(i, j, k);
				}
			}
		}
		vector<vector<bool>>(n, vector<bool>(n, false)).swap(visited);
		ans = max(temp, ans);
	}
	cout << ans;
	return 0;
}