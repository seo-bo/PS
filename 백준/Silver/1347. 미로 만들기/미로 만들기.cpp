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
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<char>>v(201, vector<char>(201, '?'));
	vector<vector<int>>dir = { {1,0},{0,1},{-1,0},{0,-1} };
	int x = 100, y = 100, d = 0, n = 0;
	int sx = 100, sy = 100, ex = 100, ey = 100;
	v[100][100] = '.';
	string str;
	cin >> n >> str;
	for (auto& i : str)
	{
		if (i == 'R')
		{
			d = (d + 3) % 4;
		}
		else if (i == 'L')
		{
			d = (d + 1) % 4;
		}
		else if (i == 'F')
		{
			x = x + dir[d][0];
			y = y + dir[d][1];
			v[x][y] = '.';
		}
		sx = min(sx, x), ex = max(ex, x), sy = min(sy, y), ey = max(ey, y);
	}
	for (int i = sx; i <= ex; ++i)
	{
		for (int j = sy; j <= ey; ++j)
		{
			if (v[i][j] != '.')
			{
				cout << '#';
			}
			else
			{
				cout << v[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}