#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<char, int> mm = { {'A',0}, {'C',1}, {'T',2}, {'G',3} };
	vector<vector<int>>base(4, vector<int>(4, 0));
	int n = 0;
	cin >> n;
	vector<string> dna(n);
	for (auto& i : dna)
	{
		cin >> i;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = 0; k < dna[i].size(); ++k)
			{
				base[mm[dna[i][k]]][mm[dna[j][k]]]++;
			}
		}
	}
	vector<vector<vector<int>>>dp(4, vector<vector<int>>(4, vector<int>(1000, -160)));
	function<int(int, int, int)> dfs = [&](int x, int y, int score)
		{
			if (x >= 4)
			{
				if (score == 320)
				{
					return 0;
				}
				else
				{
					return (int)-1e8;
				}
			}
			if (dp[x][y][score] != -160)
			{
				return dp[x][y][score];
			}
			int nx = x;
			int ny = y + 1;
			if (ny >= 4)
			{
				nx++;
				ny = nx;
			}
			int res = -1e8;
			if (x == y)
			{
				for (int i = 1; i <= 10; ++i)
				{
					res = max(res, dfs(nx, ny, score - i) + base[x][y] * i);
				}
			}
			else
			{
				for (int i = -10; i <= 10; ++i)
				{
					res = max(res, dfs(nx, ny, score - 2 * i) + base[x][y] * i + base[y][x] * i);
				}
			}
			return dp[x][y][score] = res;
		};
	lb ans = dfs(0, 0, 320);
	cout << fixed << setprecision(5) << ans / (n * (n - 1) / 2);
	return 0;
}
