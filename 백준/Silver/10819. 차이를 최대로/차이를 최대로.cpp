#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int ans = 0;
	function<void(int, int, int)> dfs = [&](int mask, int sum, int pre) ->void
		{
			bool visited = true;
			for (int i = 0; i < n; ++i)
			{
				if (!(mask & (1 << i)))
				{
					visited = false;
					dfs(mask | (1 << i), sum + abs(v[pre] - v[i]), i);
				}
			}
			if (visited)
			{
				ans = max(ans, sum);
				return;
			}
		};
	for (int i = 0; i < n; ++i)
	{
		dfs(1 << i, 0, i);
	}
	cout << ans;
	return 0;
}