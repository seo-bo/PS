#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	function<void(int, ll)>dfs = [&](int depth, ll num)
		{
			if (depth == n)
			{
				ans += (num % 3 == 0);
				return;
			}
			for (int i = 0; i <= 2; ++i)
			{
				if (depth == 0 && i == 0)
				{
					continue;
				}
				dfs(depth + 1, num * 10LL + i);
			}
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}