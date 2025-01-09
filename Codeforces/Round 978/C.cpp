#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<string>v(2);
		for (int i = 0; i < 2; ++i)
		{
			cin >> v[i];
		}
		map<pii, int>dp;
		function<int(pii)> dfs = [&](pii p) -> int
			{
				if (p.first == n || p.second == n)
				{
					return 0;
				}
				if (dp.find(p) != dp.end())
				{
					return dp[p];
				}
				int cost = 0;
				if (p.first == p.second)
				{
					if (p.first + 1 < n)
					{
						int a = 0;
						a += (v[0][p.first] == 'A');
						a += (v[0][p.first + 1] == 'A');
						a += (v[1][p.second] == 'A');
						cost = max(cost, dfs(make_pair(p.first + 2, p.second + 1)) + a / 2);
					}
					if (p.second + 1 < n)
					{
						int a = 0;
						a += (v[0][p.first] == 'A');
						a += (v[1][p.second + 1] == 'A');
						a += (v[1][p.second] == 'A');
						cost = max(cost, dfs(make_pair(p.first + 1, p.second + 2)) + a / 2);
					}
				}
				else
				{
					if (p.first > p.second)
					{
						int a = 0;
						a += (v[0][p.first] == 'A');
						a += (v[1][p.second] == 'A');
						a += (v[1][p.second + 1] == 'A');
						cost = max(cost, dfs(make_pair(p.first + 1, p.second + 2)) + a / 2);
					}
					if (p.second > p.first)
					{
						int a = 0;
						a += (v[0][p.first + 1] == 'A');
						a += (v[0][p.first] == 'A');
						a += (v[1][p.second] == 'A');
						cost = max(cost, dfs(make_pair(p.first + 2, p.second + 1)) + a / 2);
					}
				}
				if (p.first + 2 < n && p.second + 2 < n)
				{
					int a = 0, b = 0;
					for (int i = 0; i < 3; ++i)
					{
						a += (v[0][p.first + i] == 'A');
						b += (v[1][p.second + i] == 'A');
					}
					cost = max(cost, dfs(make_pair(p.first + 3, p.second + 3)) + a / 2 + b / 2);
				}
				return dp[p] = max(dp[p], cost);
			};
		cout << dfs(make_pair(0, 0)) << '\n';
	}
	return 0;
}
