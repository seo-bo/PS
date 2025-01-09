#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>>dir = { {1,2},{2,1},{-1,2},{-2,1},{-1,-2},{1,-2},{2,-1},{-2,-1} };
	int T = 0;
	cin >> T;
	auto bfs = [&](int x, int y, int dx, int dy, int n) ->int
		{
			vector<vector<bool>>visited(n, vector<bool>(n, false));
			visited[x][y] = true;
			queue<tuple<int, int, int>>q;
			q.push(make_tuple(x, y, 0));
			while (!q.empty())
			{
				tuple<int, int, int> cur = q.front();
				if (get<0>(cur) == dx && get<1>(cur) == dy)
				{
					return get<2>(cur);
				}
				q.pop();
				for (int i = 0; i < 8; ++i)
				{
					int nx = get<0>(cur) + dir[i][0];
					int ny = get<1>(cur) + dir[i][1];
					if (nx >= 0 && ny >= 0 && nx < n && ny < n)
					{
						if (!visited[nx][ny])
						{
							visited[nx][ny] = true;
							q.push(make_tuple(nx, ny, get<2>(cur) + 1));
						}
					}
				}
			}
		};
	while (T--)
	{
		int n = 0, x = 0, y = 0, dx = 0, dy = 0;
		cin >> n >> x >> y >> dx >> dy;
		cout << bfs(x, y, dx, dy, n) << '\n';
	}
	return 0;
}