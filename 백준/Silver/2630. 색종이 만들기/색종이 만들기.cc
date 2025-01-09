#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>ans(2);
	vector<vector<int>>v(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}
	function<void(int, int, int)> solve = [&](int x, int y, int n) ->void
		{
			bool check = true;
			int pivot = v[x][y];
			for (int i = x; i < x + n; ++i)
			{
				for (int j = y; j < y + n; ++j)
				{
					if (pivot != v[i][j])
					{
						check = false;
						break;
					}
				}
			}
			if (check)
			{
				ans[pivot]++;
				return;
			}
			solve(x, y, n / 2);
			solve(x + n / 2, y, n / 2);
			solve(x + n / 2, y + n / 2, n / 2);
			solve(x, y + n / 2, n / 2);
		};
	solve(0, 0, n);
	cout << ans[0] << '\n' << ans[1];
	return 0;
}