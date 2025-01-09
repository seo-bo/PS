#include <bits/stdc++.h>
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
	int n = 0, m = 0, cnt = 0, ans = 0;
	cin >> n >> m;
	cnt = n * n;
	vector<vector<int>>v(n, vector<int>(n, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == -1)
			{
				cnt--;
			}
		}
	}
	auto bfs = [&](int x, int y, int color)
		{
			int cnt = 1, zeros = 0;
			pii pos = make_pair(x, y);
			vector<vector<bool>>visited(n, vector<bool>(n, false));
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
					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						if (!visited[nx][ny] && (v[nx][ny] == color || v[nx][ny] == 0))
						{
							auto [c, d] = pos;
							if (v[nx][ny] && (nx < c || (nx == c && ny < d)))
							{
								pos = make_pair(nx, ny);
							}
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
							cnt++;
							zeros += (v[nx][ny] == 0);
						}
					}
				}
			}
			return make_tuple(cnt, zeros, visited, pos);
		};
	auto G = [&]()
		{
			for (int i = 0; i < n; ++i) // 열
			{
				pii empty = make_pair(-1, -1);
				for (int j = n - 1; j >= 0; --j) // 행
				{
					if (v[j][i] == -1)
					{
						empty = make_pair(-1, -1);
					}
					else if (v[j][i] == -2 && empty == make_pair(-1, -1))
					{
						empty = make_pair(j, i);
					}
					else if (v[j][i] != -1 && v[j][i] != -2 && empty != make_pair(-1, -1))
					{
						auto [a, b] = empty;
						swap(v[a][b], v[j][i]);
						empty = make_pair(a - 1, b);
					}
				}
			}
		};
	auto rot = [&]
		{
			vector<vector<int>>tt(n, vector<int>(n, 0));
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					tt[n - 1 - j][i] = v[i][j];
				}
			}
			v = tt;
		};
	auto check = [&](tuple<int, int, vector<vector<bool>>, pii> pp, tuple<int, int, vector<vector<bool>>, pii> pivot)
		{
			auto [a, b, c, _] = pp;
			auto [d, e, f, __] = pivot;
			if (d < a || (d == a && e < b) || (d == a && e == b && __.first < _.first) || (d == a && e == b && __.first == _.first && __.second < _.second))
			{
				return pp;
			}
			return pivot;
		};
	while (cnt)
	{
		auto pivot = make_tuple(0, 0, vector<vector<bool>>(), pii());
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (v[i][j] < 1)
				{
					continue;
				}
				auto pp = bfs(i, j, v[i][j]);
				pivot = check(pp, pivot);
			}
		}
		auto [_, __, ___, ____] = pivot;
		if (_ < 2)
		{
			break;
		}
		ans += _ * _;
		cnt -= _;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (___[i][j])
				{
					v[i][j] = -2;
				}
			}
		}
		G();
		rot();
		G();
	}
	cout << ans;
	return 0;
}