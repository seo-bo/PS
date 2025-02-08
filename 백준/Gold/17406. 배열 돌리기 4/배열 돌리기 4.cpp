#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0, ans = INT_MAX;
	cin >> n >> m >> k;
	vector<vector<int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
	vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
	vector<tuple<int, int, int>> q(k);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (auto& i : q)
	{
		auto& [a, b, c] = i;
		cin >> a >> b >> c;
	}
	auto move = [&](int r, int c, int s, vector<vector<int>> V)
		{
			int sx = r - s, sy = c - s, ex = r + s, ey = c + s;
			while (sx < ex && sy < ey)
			{
				deque<int> temp;
				int x = sx, y = sy, d = 0;
				while (true)
				{
					temp.push_back(V[x][y]);
					int nx = x + dir[d][0];
					int ny = y + dir[d][1];
					if (nx < sx || nx > ex || ny < sy || ny > ey)
					{
						d = (d + 1) % 4;
						nx = x + dir[d][0];
						ny = y + dir[d][1];
					}
					x = nx;
					y = ny;
					if (x == sx && y == sy)
					{
						break;
					}
				}
				x = sx, y = sy, d = 0;
				temp.push_front(temp.back());
				temp.pop_back();
				while (true)
				{
					V[x][y] = temp.front();
					temp.pop_front();
					int nx = x + dir[d][0];
					int ny = y + dir[d][1];
					if (nx < sx || nx > ex || ny < sy || ny > ey)
					{
						d = (d + 1) % 4;
						nx = x + dir[d][0];
						ny = y + dir[d][1];
					}
					x = nx;
					y = ny;
					if (x == sx && y == sy)
					{
						break;
					}
				}
				sx++, sy++;
				ex--, ey--;
			}
			return V;
		};
	function<void(int, vector<vector<int>>)> dfs = [&](int mask, vector<vector<int>>now)
		{
			if (mask == ((1 << k) - 1))
			{
				for (int i = 1; i <= n; ++i)
				{
					int temp = 0;
					for (int j = 1; j <= m; ++j)
					{
						temp += now[i][j];
					}
					ans = min(temp, ans);
				}
				return;
			}
			for (int i = 0; i < k; ++i)
			{
				if (!(mask & (1 << i)))
				{
					auto [a, b, c] = q[i];
					vector<vector<int>>temp = move(a, b, c, now);
					dfs(mask | (1 << i), temp);
				}
			}
		};
	dfs(0, v);
	cout << ans;
	return 0;
}