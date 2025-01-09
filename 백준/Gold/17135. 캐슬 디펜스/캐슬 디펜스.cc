#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, d = 0, ans = 0;
	cin >> n >> m >> d;
	vector<vector<int>>v(n, vector<int>(m));
	vector<vector<int>>dir = { {0,-1},{-1,0},{0,1} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<pii>pivot;
	auto bfs = [&](vector<vector<int>> t, set<pii>& s)
		{
			for (auto& [i, j] : pivot)
			{
				queue<ti>q;
				vector<vector<bool>> visited(n, vector<bool>(m, false));
				q.push(make_tuple(i - 1, j, 1));
				visited[i - 1][j] = true;
				while (!q.empty())
				{
					auto [x, y, c] = q.front();
					q.pop();
					if (t[x][y])
					{
						s.insert(make_pair(x, y));
						break;
					}
					for (int k = 0; k < 3; ++k)
					{
						int nx = x + dir[k][0];
						int ny = y + dir[k][1];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && c < d)
						{
							q.push(make_tuple(nx, ny, c + 1));
							visited[nx][ny] = true;
						}
					}
				}
			}
		};
	auto down = [&](vector<vector<int>>& vv)
		{
			for (int i = n - 1; i > 0; --i)
			{
				for (int j = 0; j < m; ++j)
				{
					vv[i][j] = vv[i - 1][j];
				}
			}
			for (int i = 0; i < m; ++i)
			{
				vv[0][i] = 0;
			}
		};
	auto solve = [&]
		{
			int cnt = 0;
			vector<vector<int>>temp = v;
			for (int i = 0; i < n; ++i)
			{
				set<pii>s;
				bfs(temp, s);
				cnt += (int)s.size();
				for (auto& [x, y] : s)
				{
					temp[x][y] = 0;
				}
				down(temp);
			}
			ans = max(ans, cnt);
			return;
		};
	function<void(int, int)> dfs = [&](int depth, int st)
		{
			if (depth == 3)
			{
				solve();
				return;
			}
			for (int i = st; i < m; ++i)
			{
				pivot.push_back(make_pair(n, i));
				dfs(depth + 1, i + 1);
				pivot.pop_back();
			}
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}