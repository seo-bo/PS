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
	int h = 0, w = 0;
	cin >> h >> w;
	int a = 0, b = 0;
	cin >> a >> b;
	--a;
	--b;
	vector<string> grid(h);
	for (int i = 0; i < h; ++i)
	{
		cin >> grid[i];
	}
	string s;
	cin >> s;
	int x = a, y = b;
	for (char move : s)
	{
		if (move == 'L')
		{
			if (y > 0 && grid[x][y - 1] == '.')
			{
				--y;
			}
		}
		else if (move == 'R')
		{
			if (y < w - 1 && grid[x][y + 1] == '.') {
				++y;
			}
		}
		else if (move == 'U')
		{
			if (x > 0 && grid[x - 1][y] == '.')
			{
				--x;
			}
		}
		else if (move == 'D')
		{
			if (x < h - 1 && grid[x + 1][y] == '.')
			{
				++x;
			}
		}
	}
	cout << (x + 1) << " " << (y + 1);
	return 0;
}
