#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<int, int, int>ti;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>em, tea;
	vector<vector<char>>v(n, vector<char>(n));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1}, {0,1} };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 'T')
			{
				tea.push_back(make_pair(i, j));
			}
			else if (v[i][j] == 'X')
			{
				em.push_back(make_pair(i, j));
			}
		}
	}
	auto check = [&]
		{
			for (auto [x, y] : tea)
			{
				for (int i = 0; i < 4; ++i)
				{
					int nx = x, ny = y;
					while (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						if (v[nx][ny] == 'O')
						{
							break;
						}
						if (v[nx][ny] == 'S')
						{
							return false;
						}
						nx = nx + dir[i][0];
						ny = ny + dir[i][1];
					}
				}
			}
			return true;
		};
	function<void(int, int, int)> dfs = [&](int depth, int start, int mask)
		{
			if (depth == 3)
			{
				if (check())
				{
					cout << "YES";
					exit(0);
				}
				return;
			}
			for (int i = start; i < em.size(); ++i)
			{
				if (!(mask & (1 << i)))
				{
					auto [x, y] = em[i];
					v[x][y] = 'O';
					dfs(depth + 1, i + 1, mask | (1 << i));
					v[x][y] = 'X';
				}
			}
		};
	dfs(0, 0, 0);
	cout << "NO";
	return 0;
}