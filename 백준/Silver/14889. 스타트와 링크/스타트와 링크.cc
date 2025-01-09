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
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}
	ll ans = LLONG_MAX;
	vector<bool>visited(n, false);
	function<void(int, int)> dfs = [&](int start, int depth) ->void
		{
			if (depth == n / 2)
			{
				ll A = 0, B = 0;
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < n; ++j)
					{
						if (visited[i] && visited[j])
						{
							A += v[i][j];
						}
						else if (!visited[i] && !visited[j])
						{
							B += v[i][j];
						}
					}
				}
				ans = min(ans,llabs(A - B));
				return;
			}
			for (int i = start; i < n; ++i)
			{
				visited[i] = true;
				dfs(i + 1, depth + 1);
				visited[i] = false;
			}
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}