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
	int n = 0, h = 0, ans = INT_MAX;
	cin >> n >> h;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	function<void(int, int)> dfs = [&](int depth, int sum) ->void
		{
			if (sum >= h)
			{
				ans = min(ans, abs(sum - h));
				return;
			}
			if (depth >= n)
			{
				return;
			}
			dfs(depth + 1, sum);
			dfs(depth + 1, sum + v[depth]);
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}