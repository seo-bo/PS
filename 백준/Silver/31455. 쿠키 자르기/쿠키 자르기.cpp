#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int>tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
		vector<vector<int>>prefix(n + 1, vector<int>(n + 1, 0));
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 1; j <= n; ++j)
			{
				v[i][j] = str[j - 1] - '0';
				ans += v[i][j];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				prefix[i][j] = v[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
			}
		}
		auto query = [&](int sx, int sy, int ex, int ey)
			{
				return prefix[ex][ey] - prefix[sx - 1][ey] - prefix[ex][sy - 1] + prefix[sx - 1][sy - 1];
			};
		function<void(int, int, int)> dfs = [&](int x, int y, int size)
			{
				if (size == 1)
				{
					return;
				}
				int pivot = size >> 1;
				vector<tp>temp = { make_tuple(x, y, x + pivot - 1, y + pivot - 1),
				make_tuple(x, y + pivot, x + pivot - 1, y + 2 * pivot - 1),
				make_tuple(x + pivot, y, x + 2 * pivot - 1, y + pivot - 1) ,
				make_tuple(x + pivot, y + pivot, x + 2 * pivot - 1, y + 2 * pivot - 1) };
				int sum = query(x, y, x + size - 1, y + size - 1) % 4;
				for (int i = 0; i < 4; ++i)
				{
					auto& [a, b, c, d] = temp[i];
					if (sum == i)
					{
						ans -= query(a, b, c, d);
					}
					else
					{
						dfs(a, b, pivot);
					}
				}
			};
		dfs(1, 1, n);
		cout << ans << '\n';
	}
	return 0;
}