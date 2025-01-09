#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, x = 0, y = 0;
	cin >> n >> m >> x >> y;
	vector<vector<char>>v(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
		}
	}
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	string d;
	cin >> d;
	map<char, int>mm = { {'L',2},{'R',3},{'U',0},{'D',1} };
	int ans = 0;
	x--;
	y--;
	for (auto& i : d)
	{
		int nx = x + dir[mm[i]][0];
		int ny = y + dir[mm[i]][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#')
		{
			if (v[nx][ny] == '@')
			{
				ans++;
				v[nx][ny] = '.';
			}
			x = nx;
			y = ny;
		}
	}
	cout << x + 1 << ' ' << y + 1 << ' ' << ans;
	return 0;
}
