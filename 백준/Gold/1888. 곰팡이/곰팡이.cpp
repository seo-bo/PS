#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (auto& i : v)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			i[j] = str[j] - '0';
		}
	}
	auto cal = [&]
		{
			vector<vector<bool>>visited(n, vector<bool>(m, false));
			int cnt = 0, xx = 0, yy = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (v[i][j])
					{
						xx = i, yy = j;
						cnt++;
					}
				}
			}
			if (!cnt)
			{
				return true;
			}
			queue<pii>q;
			q.push(make_pair(xx, yy));
			visited[xx][yy] = true;
			cnt--;
			vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
			while (!q.empty())
			{
				auto [x, y] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && v[nx][ny])
					{
						visited[nx][ny] = true;
						cnt--;
						q.push(make_pair(nx, ny));
					}
				}
			}
			return (cnt == 0);
		};
	int ans = 0;
	while (!cal())
	{
		vector<vector<int>>temp(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (!v[i][j])
				{
					continue;
				}
				int cost = v[i][j];
				int sx = max(0, i - cost), ex = min(n - 1, i + cost);
				int sy = max(0, j - cost), ey = min(m - 1, j + cost);
				for (int k = sx; k <= ex; ++k)
				{
					for (int z = sy; z <= ey; ++z)
					{
						temp[k][z] = max(temp[k][z], cost);
					}
				}
			}
		}
		v = move(temp);
		ans++;
	}
	cout << ans;
	return 0;
}