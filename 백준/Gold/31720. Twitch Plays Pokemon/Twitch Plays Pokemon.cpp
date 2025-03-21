#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<char>>v(n, vector<char>(n));
	unordered_map<char, int>mm = { {'U',0},{'D',1},{'L',2},{'R',3} };
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			v[i][j] = str[j];
			if (str[j] == 'S')
			{
				sx = i, sy = j;
			}
			else if (str[j] == 'E')
			{
				ex = i, ey = j;
			}
		}
	}
	string A, B;
	cin >> A >> B;
	int alen = A.size(), blen = B.size();
	vector<vector<vector<vector<ll>>>>dp(n, vector<vector<vector<ll>>>(n, vector<vector<ll>>((int)A.size() + 2, vector<ll>((int)B.size() + 2, -1))));
	auto check = [&](int x, int y, int o)
		{
			int nx = x + dir[o][0];
			int ny = y + dir[o][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] != '#')
			{
				return true;
			}
			return false;
		};
	function<ll(int, int, int, int)> dfs = [&](int x, int y, int i, int j)
		{
			if (x == ex && y == ey)
			{
				return 0LL;
			}
			if (alen == i && blen == j)
			{
				return (ll)INT_MAX;
			}
			if (dp[x][y][i][j] != -1)
			{
				return dp[x][y][i][j];
			}
			ll res = INT_MAX;
			if (i < alen)
			{
				int pivot = mm[A[i]];
				bool f = check(x, y, pivot);
				int nx = x, ny = y;
				if (f)
				{
					nx = x + dir[pivot][0];
					ny = y + dir[pivot][1];
				}
				res = min(res, dfs(nx, ny, i + 1, j) + 1LL);
			}
			if (j < blen)
			{
				int pivot = mm[B[j]];
				bool f = check(x, y, pivot);
				int nx = x, ny = y;
				if (f)
				{
					nx = x + dir[pivot][0];
					ny = y + dir[pivot][1];
				}
				res = min(res, dfs(nx, ny, i, j + 1) + 1LL);
			}
			return dp[x][y][i][j] = res;
		};
	ll ans = dfs(sx, sy, 0, 0);
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}