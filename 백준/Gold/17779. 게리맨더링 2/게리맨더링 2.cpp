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
	int n = 0, ans = INT_MAX;
	cin >> n;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	auto check = [&](int x, int y)
		{
			return (x >= 1 && x <= n && y >= 1 && y <= n);
		};
	auto solve = [&](int x, int y, int d1, int d2)
		{
			vector<vector<int>>grid(n + 1, vector<int>(n + 1, 0));
			vector<int>temp(6, 0);
			for (int r = 1; r <= n; r++)
			{
				for (int c = 1; c <= n; c++) // *5번 구역 경계선 조건 처리해주기*
				{
					if (r < x + d1 && c <= y && !(r >= x && r + c >= x + y))
					{
						temp[1] += v[r][c];
					}
					else if (r <= x + d2 && y < c && !(r >= x && c - r <= y - x))
					{
						temp[2] += v[r][c];
					}
					else if (x + d1 <= r && c < y - d1 + d2 && !(r <= x + d1 + d2 && c - r >= y - x - 2 * d1))
					{
						temp[3] += v[r][c];
					}
					else if (x + d2 < r && y - d1 + d2 <= c && !(r <= x + d1 + d2 && c + r <= y + x + 2 * d2))
					{
						temp[4] += v[r][c];
					}
					else
					{
						temp[5] += v[r][c];
					}
				}
			}
			int maxi = *max_element(temp.begin() + 1, temp.end());
			int mini = *min_element(temp.begin() + 1, temp.end());
			return maxi - mini;
		};
	for (int x = 1; x <= n; ++x)
	{
		for (int y = 1; y <= n; ++y)
		{
			for (int d1 = 1; d1 <= n; ++d1)
			{
				for (int d2 = 1; d2 <= n; ++d2)
				{
					if (x + d1 + d2 <= n && y + d2 <= n && y - d1 >= 1)
					{
						ans = min(ans, solve(x, y, d1, d2));
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}