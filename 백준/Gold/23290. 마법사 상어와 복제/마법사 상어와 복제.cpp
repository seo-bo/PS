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
	vector<vector<vector<int>>>v(4, vector<vector<int>>(4));
	vector<vector<int>>smell(4, vector<int>(4, 0));
	vector<vector<int>>dir = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
	vector<vector<int>>shark = { {-1,0},{0,-1},{1,0},{0,1} };
	deque<ti>fish;
	int m = 0, s = 0, sx = 0, sy = 0, pivot = -1;
	cin >> m >> s;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		v[--a][--b].push_back(--c);
		fish.push_back(make_tuple(a, b, c));
	}
	cin >> sx >> sy;
	sx--, sy--;
	auto eat = [&](int x, int y, vector<vector<int>>ts, vector<vector<vector<int>>>& ans, vector<vector<vector<int>>> temp, vector<int> st)
		{
			vector<vector<int>>ss = ts;
			int cnt = 0;
			for (auto& i : st)
			{
				int nx = x + shark[i][0];
				int ny = y + shark[i][1];
				if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4)
				{
					if (!temp[nx][ny].empty())
					{
						cnt += temp[nx][ny].size();
						temp[nx][ny].clear();
						ss[nx][ny] = -3;
					}
					x = nx;
					y = ny;
				}
				else
				{
					return;
				}
			}
			if (cnt > pivot)
			{
				smell = ss;
				ans = temp;
				pivot = cnt;
				sx = x, sy = y;
			}
		};
	auto move = [&]
		{
			pivot = -1;
			vector<vector<vector<int>>>temp(4, vector<vector<int>>(4));
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					for (auto& k : v[i][j])
					{
						bool check = false;
						for (int d = 0; d < 8; ++d)
						{
							int dd = (k - d + 8) % 8;
							int nx = i + dir[dd][0];
							int ny = j + dir[dd][1];
							if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !smell[nx][ny] && !(nx == sx && ny == sy))
							{
								temp[nx][ny].push_back(dd);
								check = true;
								break;
							}
						}
						if (!check)
						{
							temp[i][j].push_back(k);
						}
					}
				}
			}
			vector<vector<vector<int>>>cc = temp;
			vector<vector<int>>sss = smell;
			int tx = sx, ty = sy;
			for (int _ = 0; _ < 4; ++_)
			{
				for (int __ = 0; __ < 4; ++__)
				{
					for (int ___ = 0; ___ < 4; ++___)
					{
						vector<int>st = { _,__,___ };
						eat(tx, ty, sss, temp, cc, st);
					}
				}
			}
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (smell[i][j] < 0)
					{
						smell[i][j]++;
					}
				}
			}
			while (!fish.empty())
			{
				auto [a, b, c] = fish.front();
				temp[a][b].push_back(c);
				fish.pop_front();
			}
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					for (auto& k : temp[i][j])
					{
						fish.push_back(make_tuple(i, j, k));
					}
				}
			}
			v = temp;
		};
	while (s--)
	{
		move();
	}
	ll ans = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			ans += (ll)v[i][j].size();
		}
	}
	cout << ans;
	return 0;
}