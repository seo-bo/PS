#include <bits/stdc++.h>
#include <unordered_set>
#define INF INT_MIN
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>v(n, vector<ll>(m, 0));
	vector<vector<vector<ll>>>dp(n, vector<vector<ll>>(m, vector<ll>(3, INF)));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	function<ll(int, int, int)> dfs = [&](int x, int y, int d)->ll
		{
			// d = -1 왼쪽, d = 0 위, d = 1 오른쪽
			if (x == n - 1 && y == m - 1)
			{
				return v[x][y];
			}
			if (dp[x][y][d + 1] != INF)
			{
				return dp[x][y][d + 1];
			}
			ll cnt = INF;
			if (d != 1 && y - 1 >= 0) 
			{
				cnt = max(cnt, dfs(x, y - 1, -1));
			}
			if (x + 1 < n)
			{
				cnt = max(cnt, dfs(x + 1, y, 0));
			}
			if (d != -1 && y + 1 < m)
			{
				cnt = max(cnt, dfs(x, y + 1, 1));
			}
			return dp[x][y][d + 1] = v[x][y] + cnt;
		};
	cout << dfs(0, 0, 0);
	return 0;
}