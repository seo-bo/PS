#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<char>>v(1 + (n - 1) * 4, vector<char>(1 + (n - 1) * 4));
	function<void(int, int, int, char)> solve = [&](int x, int y, int n, char pivot) ->void
		{
			for (int i = x; i < x + n; ++i)
			{
				if (i == x || i == x + n - 1)
				{
					for (int j = y; j < y + n; ++j)
					{
						v[i][j] = pivot;
					}
				}
				else
				{
					v[i][y] = v[i][y + n - 1] = pivot;
				}
			}
			if (n == 1)
			{
				return;
			}
			if (pivot == '*')
			{
				solve(x + 1, y + 1, n - 2, ' ');
			}
			else
			{
				solve(x + 1, y + 1, n - 2, '*');
			}
		};
	solve(0, 0, 1 + (n - 1) * 4, '*');
	for (int i = 0; i < 1 + (n - 1) * 4; ++i)
	{
		for (int j = 0; j < 1 + (n - 1) * 4; ++j)
		{
			cout << v[i][j];
		}
		if (i < (n - 1) * 4)
		{
			cout << '\n';
		}
	}
	return 0;
}