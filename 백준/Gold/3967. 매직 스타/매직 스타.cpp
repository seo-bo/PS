#include <bits/stdc++.h>
using namespace std;
typedef long double lb;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string grid[5];
	vector<bool>visited(20, false);
	vector<pii>point;
	auto conv = [&](char st) -> int
		{
			return (st - 'A');
		};
	auto rconv = [&](char st) -> char
		{
			return (st + 'A');
		};
	auto check = [&]() -> bool
		{
			if ((conv(grid[0][4]) + conv(grid[1][3]) + conv(grid[2][2]) + conv(grid[3][1])) != 22)
			{
				return false;
			}
			if ((conv(grid[0][4]) + conv(grid[1][5]) + conv(grid[2][6]) + conv(grid[3][7])) != 22)
			{
				return false;
			}
			if ((conv(grid[3][1]) + conv(grid[3][3]) + conv(grid[3][5]) + conv(grid[3][7])) != 22)
			{
				return false;
			}
			if ((conv(grid[1][1]) + conv(grid[2][2]) + conv(grid[3][3]) + conv(grid[4][4])) != 22)
			{
				return false;
			}
			if ((conv(grid[1][7]) + conv(grid[2][6]) + conv(grid[3][5]) + conv(grid[4][4])) != 22)
			{
				return false;
			}
			if ((conv(grid[1][1]) + conv(grid[1][3]) + conv(grid[1][5]) + conv(grid[1][7])) != 22)
			{
				return false;
			}
			return true;
		};
	int cnt = 12;
	function<void(int)> dfs = [&](int start) -> void
		{
			if (cnt == 12)
			{
				if (check())
				{
					for (auto& i : grid)
					{
						for (auto& j : i)
						{
							cout << j;
						}
						cout << "\n";
					}
					exit(0);
				}
				return;
			}
			for (int i = 0; i < 12; ++i)
			{
				if (!visited[i])
				{
					grid[point[start].first][point[start].second] = rconv(i);
					visited[i] = true;
					cnt++;
					dfs(start + 1);
					cnt--;
					visited[i] = false;
					grid[point[start].first][point[start].second] = 'x';
				}
			}
		};
	
	for (int i = 0; i < 5; ++i)
	{
		cin >> grid[i];
		for (int k = 0; k < grid[i].length(); ++k)
		{
			if (grid[i][k] != '.' && grid[i][k] != 'x')
			{
				visited[conv(grid[i][k])] = true;
			}
			else if (grid[i][k] == 'x')
			{
				cnt--;
				point.push_back(make_pair(i, k));
			}
		}
	}
	dfs(0);
	return 0;
}