#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	int r = 0, c = 0, sx = INT_MAX, sy = INT_MAX, ex = -INT_MAX, ey = -INT_MAX;
	cin >> r >> c;
	vector<vector<char>>v(r, vector<char>(c));
	queue<pii>q;
	queue<pii>cam;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 'X')
			{
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; ++i)
		{
			int nx = a + dir[i][0];
			int ny = b + dir[i][1];
			if (!(nx >= 0 && ny >= 0 && nx < r && ny < c) || v[nx][ny] == '.')
            {
                cnt++;
            }
		}
		if (cnt >= 3)
		{
			cam.push(make_pair(a, b));
		}
	}
	while (!cam.empty())
	{
		auto [a, b] = cam.front();
		cam.pop();
		v[a][b] = '.';
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (v[i][j] == 'X')
			{
				sx = min(sx, i);
				ex = max(ex, i);
				sy = min(sy, j);
				ey = max(ey, j);
			}
		}
	}
	for (int i = sx; i <= ex; ++i)
	{
		for (int j = sy; j <= ey; ++j)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}
	return 0;
}