#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<char>>v(5, vector<char>(5));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			int temp = 0;
			cin >> temp;
			j = temp + '0';
		}
	}
	unordered_map<string, int>m;
	string temp;
	function<void(int, int)> dfs = [&](int x, int y) ->void
		{
			if (temp.length() == 6)
			{
				m[temp]++;
				return;
			}
			if (x + 1 < 5)
			{
				temp.push_back(v[x][y]);
				dfs(x + 1, y);
				temp.pop_back();
			}
			if (x - 1 >= 0)
			{
				temp.push_back(v[x][y]);
				dfs(x - 1, y);
				temp.pop_back();
			}
			if (y + 1 < 5)
			{
				temp.push_back(v[x][y]);
				dfs(x, y + 1);
				temp.pop_back();
			}
			if (y - 1 >= 0)
			{
				temp.push_back(v[x][y]);
				dfs(x, y - 1);
				temp.pop_back();
			}
		};
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			dfs(i, j);
		}
	}
	cout << m.size();
	return 0;
}