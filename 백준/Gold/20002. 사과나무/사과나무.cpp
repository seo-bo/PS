#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int>>prefix(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + v[i][j];
		}
	}
	auto query = [&](int x, int y, int siz)
		{
			int sx = x, sy = y, ex = sx + siz, ey = sy + siz;
			if (!(sx >= 1 && sx <= n && sy >= 1 && sy <= n && ex >= 1 && ex <= n && ey >= 1 && ey <= n))
			{
				return INT_MIN;
			}
			return prefix[ex][ey] - prefix[ex][sy - 1] - prefix[sx - 1][ey] + prefix[sx - 1][sy - 1];
		};
	int ans = INT_MIN;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 0; k <= n; ++k)
			{
				ans = max(ans, query(i, j, k));
			}
		}
	}
	cout << ans;
	return 0;
}