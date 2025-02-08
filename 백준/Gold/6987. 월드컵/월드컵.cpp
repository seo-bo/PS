#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>>v(6, vector<int>(3, 0));
	vector<vector<int>>temp(6, vector<int>(3, 0));
	vector<pii>per, dir = { {0,2},{1,1},{2,0} };
	for (int i = 0; i < 6; ++i)
	{
		for (int j = i + 1; j < 6; ++j)
		{
			per.push_back(make_pair(i, j));
		}
	}
	function<bool(int)> dfs = [&](int depth)
		{
			if (depth == 15)
			{
				for (int i = 0; i < 6; ++i)
				{
					for (int j = 0; j < 3; ++j)
					{
						if (temp[i][j] != v[i][j])
						{
							return false;
						}
					}
				}
				return true;
			}
			auto& [a, b] = per[depth];
			for (auto& [i, j] : dir)
			{
				if (v[a][i] < temp[a][i] + 1 || v[b][j] < temp[b][j] + 1)
				{
					continue;
				}
				temp[a][i]++;
				temp[b][j]++;
				if (dfs(depth + 1))
				{
					temp[a][i] = 0;
					temp[b][j] = 0;
					return true;
				}
				temp[a][i]--;
				temp[b][j]--;
			}
			return false;
		};
	int cnt = 0;
	for (int z = 0; z < 4; z++)
	{
		for (auto& i : v)
		{
			for (auto& j : i)
			{
				cin >> j;
			}
		}
		cout << dfs(0) << ' ';
	}
	return 0;
}