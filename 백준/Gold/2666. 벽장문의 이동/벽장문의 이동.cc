#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, mask = 0, q = 0;
	cin >> n;

	pii pos;
	cin >> pos.first >> pos.second;
	auto sv = [&](pii p)
		{
			return make_pair(min(p.first, p.second), max(p.first, p.second));
		};
	pos = sv(pos);
	cin >> q;
	vector<int>v(q);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n + 1, vector<int>(q + 1, INT_MAX)));
	function<int(int, int, int)> dfs = [&](int a, int b, int depth)
		{
			if (depth == q)
			{
				return 0;
			}
			if (dp[a][b][depth] != INT_MAX)
			{
				return dp[a][b][depth];
			}
			int pivot = v[depth];
			pii p1 = sv(make_pair(pivot, b));
			pii p2 = sv(make_pair(pivot, a));
			return dp[a][b][depth] = min(dfs(p1.first, p1.second, depth + 1) + abs(pivot - a), dfs(p2.first, p2.second, depth + 1) + abs(pivot - b));
		};
	cout << dfs(pos.first, pos.second, 0);
	return 0;
}