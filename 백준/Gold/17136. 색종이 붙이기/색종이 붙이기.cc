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
	cin.tie(0)->ios::sync_with_stdio(0);
	int cnt = 0, ans = INT_MAX;
	vector<vector<int>>v(10, vector<int>(10));
	vector<int>paper(6, 5);
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto check = [&](int x, int y, int size)
		{
			for (int i = x; i < x + size; ++i)
			{
				for (int j = y; j < y + size; ++j)
				{
					if (!v[i][j])
					{
						return false;
					}
				}
			}
			return true;
		};
	function<void(int, int, int)> dfs = [&](int x, int y, int sum)
		{
			if (sum >= ans)
			{
				return;
			}
			while (x < 10)
			{
				while (y < 10 && !v[x][y])
				{
					++y;
				}
				if (y == 10)
				{
					++x, y = 0;
					continue;
				}
				break;
			}
			if (x == 10)
			{
				ans = min(ans, sum);
				return;
			}
			for (int i = 5; i >= 1; --i)
			{
				if (paper[i] && x + i <= 10 && y + i <= 10)
				{
					if (check(x, y, i))
					{
						paper[i]--;
						for (int j = x; j < x + i; ++j)
						{
							for (int k = y; k < y + i; ++k)
							{
								v[j][k] = 0;
							}
						}
						dfs(x, y, sum + 1);
						for (int j = x; j < x + i; ++j)
						{
							for (int k = y; k < y + i; ++k)
							{
								v[j][k] = 1;
							}
						}
						paper[i]++;
					}
				}
			}
		};
	dfs(0, 0, 0);
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}