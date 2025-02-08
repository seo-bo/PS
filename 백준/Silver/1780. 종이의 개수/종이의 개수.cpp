#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int ans_1 = 0, ans0 = 0, ans1 = 0;
	function<void(int, int, int)> solve = [&](int x, int y, int n) ->void
		{
			int pivot = v[x][y];
			bool check = true;
			for (int i = x; i < x + n; ++i)
			{
				for (int j = y; j < y + n; ++j)
				{
					if (v[i][j] != pivot)
					{
						check = false;
						break;
					}
				}
			}
			if (check)
			{
				if (pivot)
				{
					if (pivot == 1)
					{
						ans1++;
					}
					else
					{
						ans_1++;
					}
				}
				else
				{
					ans0++;
				}
				return;
			}
			solve(x, y, n / 3);
			solve(x + n / 3, y, n / 3);
			solve(x + 2 * n / 3, y, n / 3);
			solve(x, y + n / 3, n / 3);
			solve(x + n / 3, y + n / 3, n / 3);
			solve(x + 2 * n / 3, y + n / 3, n / 3);
			solve(x, y + 2 * n / 3, n / 3);
			solve(x + n / 3, y + 2 * n / 3, n / 3);
			solve(x + 2 * n / 3, y + 2 * n / 3, n / 3);
		};
	solve(0, 0, n);
	cout << ans_1 << '\n' << ans0 << '\n' << ans1;
	return 0;
}