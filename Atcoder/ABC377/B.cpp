#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<bool>>visited(8, vector<bool>(8, false));
	auto move = [&](int x, int y, int a, int b)
		{;
			while (x >= 0 && x < 8 && y >= 0 && y < 8)
			{
				visited[x][y] = true;
				x += a;
				y += b;
			}
		};
	for (int i = 0; i < 8; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 8; ++j)
		{
			if (str[j] == '#')
			{
				move(i, 0, 0, 1);
				move(0, j, 1, 0);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (!visited[i][j])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
