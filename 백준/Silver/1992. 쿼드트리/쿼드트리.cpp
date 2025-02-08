#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<char>>grid(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];
		}
	}
	auto judge = [&](int x, int y, int n)->bool
		{
			char pivot = grid[x][y];
			for (int i = x; i < x + n; ++i)
			{
				for (int j = y; j < y + n; ++j)
				{
					if (pivot != grid[i][j])
					{
						return false;
					}
				}
			}
			return true;
		};
	function<void(int, int, int)>rec = [&](int x, int y, int n) -> void
		{
			char pivot = grid[x][y];
			if (judge(x, y, n))
			{
				cout << pivot;
				return;
			}
			cout << "(";
			rec(x, y, n / 2);
			rec(x, y + n / 2, n / 2);
			rec(x + n / 2, y, n / 2);
			rec(x + n / 2, y + n / 2, n / 2);
			cout << ")";
		};
	rec(0, 0, n);
	return 0;
}