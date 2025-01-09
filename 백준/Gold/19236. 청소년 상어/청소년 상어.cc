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
	int ans = 0, d = 0;
	vector<vector<int>>dir = { {0,0},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} }; // 반시계 회전
	vector<vector<pii>>v(4, vector<pii>(4)); // 크기, dir
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> v[i][j].first >> v[i][j].second;
			if (!i && !j)
			{
				ans = v[i][j].first;
				d = v[i][j].second;
				v[i][j] = make_pair(0, 0);
			}
		}
	}
	auto move = [&](vector<vector<pii>>& vv, int x, int y) // 물고기 이동 추적
		{
			vector<vector<pii>>temp = vv;
			vector<pii>fish(17, make_pair(-1, -1));
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (temp[i][j].first > 0)
					{
						fish[temp[i][j].first] = make_pair(i, j);
					}
				}
			}
			for (int i = 1; i <= 16; ++i)
			{
				auto [a, b] = fish[i];
				if (a == -1 && b == -1)
				{
					continue;
				}
				auto [c, d] = temp[a][b];
				for (int j = 0; j <= 9; ++j)
				{
					int td = (d + j) % 9;
					if (td > 0)
					{
						int nx = a + dir[td][0];
						int ny = b + dir[td][1];
						if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
						{
							if (!(nx == x && ny == y))
							{
								temp[a][b] = make_pair(c, td);
								swap(temp[nx][ny], temp[a][b]);
								fish[c] = make_pair(nx, ny);
								fish[temp[a][b].first] = make_pair(a, b);
								break;
							}
						}
					}
				}
			}
			return temp;
		};
	function<void(int, int, int, int, vector<vector<pii>>)> dfs = [&](int x, int y, int d, int sum, vector<vector<pii>>now)
		{
			vector<vector<pii>>temp = move(now, x, y);
			for (int i = 1; i <= 3; ++i)
			{
				int nx = x + dir[d][0] * i;
				int ny = y + dir[d][1] * i;
				if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
				{
					if (temp[nx][ny].first)
					{
						auto [a, b] = temp[nx][ny];
						temp[nx][ny] = make_pair(0, 0);
						dfs(nx, ny, b, sum + a, temp);
						temp[nx][ny] = make_pair(a, b);
					}
				}
			}
			ans = max(ans, sum);
		};
	dfs(0, 0, d, ans, v);
	cout << ans;
	return 0;
}