#include <bits/stdc++.h>
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
	int N = 0, q = 0;
	cin >> N >> q;
	int n = (1 << N);
	vector<vector<int>>v(n, vector<int>(n, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto rot = [&](int r, int c, int siz)
		{
			vector<vector<int>> temp(siz, vector<int>(siz));
			for (int i = 0; i < siz; ++i)
			{
				for (int j = 0; j < siz; ++j)
				{
					temp[j][siz - i - 1] = v[r + i][c + j];
				}
			}
			for (int i = 0; i < siz; ++i)
			{
				for (int j = 0; j < siz; ++j)
				{
					v[r + i][c + j] = temp[i][j];
				}
			}
		};
	auto melt = [&]
		{
			vector<vector<int>>temp = v;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					int cnt = 0;
					for (int k = 0; k < 4; ++k)
					{
						int nx = i + dir[k][0];
						int ny = j + dir[k][1];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny])
						{
							cnt++;
						}
					}
					if (cnt < 3)
					{
						temp[i][j] = max(temp[i][j] - 1, 0);
					}
				}
			}
			v = temp;
		};
	function<void(int, int, int, int)> dfs = [&](int x, int y, int siz, int pivot)
		{
			if (siz == pivot)
			{
				rot(x, y, siz);
				return;
			}
			int s = siz / 2;
			dfs(x, y, s, pivot);
			dfs(x + s, y, s, pivot);
			dfs(x, y + s, s, pivot);
			dfs(x + s, y + s, s, pivot);
		};
	auto bfs = [&](int x, int y)
		{
			int p = 1;
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
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] && !visited[nx][ny])
					{
						p++;
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
			return p;
		};
	while (q--)
	{
		int l = 0;
		cin >> l;
		if (l)
		{
			dfs(0, 0, n, (1 << l));
		}
		melt();
	}
	int ans = 0, mass = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ans += v[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] && !visited[i][j])
			{
				mass = max(mass, bfs(i, j));
			}
		}
	}
	cout << ans << '\n' << mass;
	return 0;
}