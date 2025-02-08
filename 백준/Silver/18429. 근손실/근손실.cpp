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
	int n = 0, k = 0, ans = 0;
	cin >> n >> k;
	vector<int>v(n);
	vector<bool>visited(n, false);
	for (auto& i : v)
	{
		cin >> i;
	}
	function<void(int, int)> dfs = [&](int depth, int sum) ->void
		{
			if (depth == n)
			{
				ans++;
				return;
			}
			for (int i = 0; i < n; ++i)
			{
				if (!visited[i] && sum - k + v[i] >= 500)
				{
					visited[i] = true;
					dfs(depth + 1, sum - k + v[i]);
					visited[i] = false;
				}
			}
		};
	dfs(0, 500);
	cout << ans;
	return 0;
}