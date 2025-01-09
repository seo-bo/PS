#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<vector<int>>v(9, vector<int>(9, 0));
	vector<pii>temp;
	auto cal = [&](int x, int y, int num)
		{
			for (int i = 0; i < 9; ++i)
			{
				if (v[x][i] == num)
				{
					return false;
				}
				if (v[i][y] == num)
				{
					return false;
				}
			}
			int xx = (x / 3) * 3;
			int yy = (y / 3) * 3;
			for (int i = xx; i < xx + 3; ++i)
			{
				for (int j = yy; j < yy + 3; ++j)
				{
					if (v[i][j] == num)
					{
						return false;
					}
				}
			}
			return true;
		};
	for (int i = 0; i < 9; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 9; ++j)
		{
			v[i][j] = str[j] - '0';
			if (!v[i][j])
			{
				temp.push_back(make_pair(i, j));
			}
		}
	}
	int len = temp.size();
	function<void(int)> dfs = [&](int depth)
		{
			if (depth == len)
			{
				for (auto& i : v)
				{
					for (auto& j : i)
					{
						cout << j;
					}
					cout << '\n';
				}
				exit(0);
			}
			auto& [x, y] = temp[depth];
			for (int i = 1; i <= 9; ++i)
			{
				if (cal(x, y, i))
				{
					v[x][y] = i;
					dfs(depth + 1);
					v[x][y] = 0;
				}
			}
		};
	dfs(0);
	return 0;
}