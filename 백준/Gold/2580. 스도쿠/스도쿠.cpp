#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<int>>v(9, vector<int>(9, 0));
	vector<pii>a;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> v[i][j];
			if (!v[i][j])
			{
				a.push_back(make_pair(i, j));
			}
		}
	}
	int siz = a.size();
	auto check = [&](int r, int c, int num) ->bool
		{
			for (int i = 0; i < 9; ++i)
			{
				if (v[r][i] == num || v[i][c] == num)
				{
					return false;
				}
			}
			r = r / 3 * 3;
			c = c / 3 * 3;
			for (int i = r; i < r + 3; ++i)
			{
				for (int j = c; j < c + 3; ++j)
				{
					if (v[i][j] == num)
					{
						return false;
					}
				}
			}
			return true;
		};
	function<void(int)>dfs = [&](int depth) ->void
		{
			if (depth == siz)
			{
				for (auto& i : v)
				{
					for (auto& j : i)
					{
						cout << j << ' ';
					}
					cout << '\n';
				}
				exit(0);
			}
			auto [nx, ny] = a[depth];
			for (int i = 1; i <= 9; ++i)
			{
				if (check(nx, ny, i))
				{
					v[nx][ny] = i;
					dfs(depth + 1);
					v[nx][ny] = 0;
				}
			}
		};
	dfs(0);
	return 0;
}