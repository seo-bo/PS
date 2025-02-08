#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<int>>dir = { {0,-1},{0,1},{-1,0},{1,0} };
	pii red, blue;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			if (str[j] == 'R')
			{
				red = make_pair(i, j);
				v[i][j] = '.';
			}
			else if (str[j] == 'B')
			{
				blue = make_pair(i, j);
				v[i][j] = '.';
			}
			else
			{
				v[i][j] = str[j];
			}
		}
	}
	queue<tuple<pii, pii, int>>q;
	q.push(make_tuple(red, blue, 0));
	bool visited[10][10][10][10][11] = { false, };
	visited[red.first][red.second][blue.first][blue.second][0] = true;
	auto move = [&](pii f, pii s, char ff, char ss, int d, int cnt)
		{
			bool flag1 = false, flag2 = false;
			int nx = f.first, ny = f.second;
			while (1)
			{
				int xx = nx + dir[d][0];
				int yy = ny + dir[d][1];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m && v[xx][yy] != '#')
				{
					if (v[xx][yy] == 'O')
					{
						flag1 = true;
						nx = -1, ny = -1;
						break;
					}
					else
					{
						nx = xx, ny = yy;
					}
				}
				else
				{
					break;
				}
			}
			f = make_pair(nx, ny);
			nx = s.first, ny = s.second;
			while (1)
			{
				int xx = nx + dir[d][0];
				int yy = ny + dir[d][1];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m && v[xx][yy] != '#' && f != make_pair(xx, yy))
				{
					if (v[xx][yy] == 'O')
					{
						flag2 = true;
						nx = -1, ny = -1;
						break;
					}
					else
					{
						nx = xx, ny = yy;
					}
				}
				else
				{
					break;
				}
			}
			s = make_pair(nx, ny);
			if (ff == 'B') // 항상 첫번째는 red 인거로
			{
				swap(f, s);
				swap(flag1, flag2);
			}
			if (flag2)
			{
				return;
			}
			else if (flag1)
			{
				cout << cnt + 1;
				exit(0);
			}
			else if (!visited[f.first][f.second][s.first][s.second][cnt + 1])
			{
				visited[f.first][f.second][s.first][s.second][cnt + 1] = true;
				q.push(make_tuple(f, s, cnt + 1));
			}
		};
	while (!q.empty()) // 왼 오 위 아
	{
		auto [r, b, cnt] = q.front();
		q.pop();
		if (cnt == 10)
		{
			continue;
		}
		(b.second < r.second) ? move(b, r, 'B', 'R', 0, cnt) : move(r, b, 'R', 'B', 0, cnt);
		(b.second > r.second) ? move(b, r, 'B', 'R', 1, cnt) : move(r, b, 'R', 'B', 1, cnt);
		(b.first < r.first) ? move(b, r, 'B', 'R', 2, cnt) : move(r, b, 'R', 'B', 2, cnt);
		(b.first > r.first) ? move(b, r, 'B', 'R', 3, cnt) : move(r, b, 'R', 'B', 3, cnt);
	}
	cout << -1;
	return 0;
}