#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int maxi = 0, idx = 0;
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(5));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> v[i][j];
		}
	}
	function<void(int, int, int, int, int)> dfs = [&](int start, int mask, int depth, int sum, int m) ->void
		{
			if (depth == 3)
			{
				if (sum >= maxi)
				{
					maxi = sum;
					idx = m + 1;
				}
			}
			for (int i = start; i < 5; ++i)
			{
				if (!(mask & (1 << i)))
				{
					mask |= (1 << i);
					dfs(i + 1, mask, depth + 1, (sum + v[m][i]) % 10, m);
					mask &= ~(1 << i);
				}
			}
		};
	for (int i = 0; i < n; ++i)
	{
		dfs(0, 0, 0, 0, i);
	}
	cout << idx;
	return 0;
}