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
	int n = 0, ans = 0;
	cin >> n;
	int x = n / 2, y = n / 2, dd = 0, cnt = 1;
	// 1 1 , 2 2 , 3 3 , 4 4 , 5 5, ..... n-1 n-1 n-1 형태이동 (2*n)-1번 이동한당
	vector<vector<int>>v(n, vector<int>(n, 0));
	vector<vector<int>>dir = { {0,-1},{1,0},{0,1},{-1,0} };
	vector<vector<tuple<int, int, int>>>pivot(4);
	pivot[0] = { {-1,1,1},{-2,0,2},{-1,0,7},{-1,-1,10},{0,-2,5},{1,-1,10},{1,0,7},{2,0,2},{1,1,1} };
	pivot[1] = { {-1,-1,1},{-1,1,1},{0,-2,2},{0,-1,7},{0,1,7},{0,2,2},{1,-1,10},{1,1,10},{2,0,5} };
	pivot[2] = { {-2,0,2},{-1,-1,1},{-1,0,7},{-1,1,10},{0,2,5},{1,-1,1},{1,0,7},{1,1,10},{2,0,2} };
	pivot[3] = { {-2,0,5},{-1,-1,10},{-1,1,10},{0,-2,2},{0,-1,7},{0,1,7},{0,2,2},{1,-1,1},{1,1,1} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto move = [&](int d)
		{
			int nx = x + dir[d][0], ny = y + dir[d][1], total = v[nx][ny];
			for (auto& [a, b, c] : pivot[d])
			{
				int xx = nx + a, yy = ny + b, cost = (total * c) / 100;
				v[nx][ny] -= cost;
				if (xx >= 0 && xx < n && yy >= 0 && yy < n)
				{
					v[xx][yy] += cost;
				}
				else
				{
					ans += cost;
				}
			}
			int ax = nx + dir[d][0], ay = ny + dir[d][1];
			if (ax >= 0 && ax < n && ay >= 0 && ay < n)
			{
				v[ax][ay] += v[nx][ny];
			}
			else
			{
				ans += v[nx][ny];
			}
			v[nx][ny] = 0;
			x = nx, y = ny;
		};
	for (int i = 0; i < 2 * (n - 1); ++i)
	{
		int r = (i / 2) + 1;
		for (int j = 0; j < r; ++j)
		{
			move(dd);
		}
		dd = (dd + 1) % 4;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		move(dd);
	}
	cout << ans;
	return 0;
}