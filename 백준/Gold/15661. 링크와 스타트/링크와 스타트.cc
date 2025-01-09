#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	ll pivot = n / 2, ans = INT_MAX;
	function<void(int, int)> dfs = [&](int depth, int mask)
		{
			if (depth == n)
			{
				ll a = 0, b = 0;
				for (int i = 0; i < n; ++i)
				{
					for (int j = i + 1; j < n; ++j)
					{
						if ((mask & (1 << i)) && (mask & (1 << j)))
						{
							a += v[i][j] + v[j][i];
						}
						else if (!(mask & (1 << i)) && !(mask & (1 << j)))
						{
							b += v[i][j] + v[j][i];
						}
					}
				}
				ans = min(ans, llabs(a - b));
				return;
			}
			dfs(depth + 1, mask | (1 << depth));
			dfs(depth + 1, mask);
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}