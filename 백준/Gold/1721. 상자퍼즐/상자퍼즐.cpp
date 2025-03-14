#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<vector<int>>>v;
	vector<int>ok;
	for (int i = 0; i < n * n; ++i)
	{
		vector<int>temp(4);
		vector<vector<int>>tt;
		int _ = 0;
		cin >> _;
		ok.push_back(_);
		for (auto& j : temp)
		{
			cin >> j;
		}
		tt.push_back(temp);
		for (int j = 0; j < 3; ++j)
		{
			rotate(temp.begin(), temp.end() - 1, temp.end());
			tt.push_back(temp);
		}
		v.push_back(tt);
	}
	vector<pii>ans(n * n);
	auto check = [&](int depth, int box, int d)
		{
			if (depth < n)
			{
				if (v[box][d][0])
				{
					return false;
				}
			}
			else if (depth >= n * (n - 1))
			{
				if (v[box][d][2])
				{
					return false;
				}
			}
			if (depth >= n)
			{
				auto& [a, b] = ans[depth - n];
				if (v[box][d][0] != v[a][b][2])
				{
					return false;
				}
			}
			if (depth % n == 0)
			{
				if (v[box][d][3])
				{
					return false;
				}
			}
			else if ((depth + 1) % n == 0)
			{
				if (v[box][d][1])
				{
					return false;
				}
			}
			if (depth % n)
			{
				auto& [a, b] = ans[depth - 1];
				if (v[box][d][3] != v[a][b][1])
				{
					return false;
				}
			}
			return true;
		};
	function<bool(int, int)> dfs = [&](int mask, int depth)
		{
			if (__builtin_popcount(mask) == n * n)
			{
				int cnt = 0;
				for (auto& [a, _] : ans)
				{
					cout << ok[a] << ' ';
					cnt++;
					if (cnt == n)
					{
						cout << '\n';
						cnt = 0;
					}
				}
				for (auto& [_, a] : ans)
				{
					cout << a << ' ';
					cnt++;
					if (cnt == n)
					{
						cout << '\n';
						cnt = 0;
					}
				}
				return true;
			}
			for (int i = 0; i < n * n; ++i)
			{
				if (mask & (1 << i))
				{
					continue;
				}
				for (int j = 0; j < 4; ++j)
				{
					if (check(depth, i, j))
					{
						ans[depth] = make_pair(i, j);
						if (dfs(mask | (1 << i), depth + 1))
						{
							return true;
						}
					}
				}
			}
			return false;
		};
	dfs(0, 0);
	return 0;
}