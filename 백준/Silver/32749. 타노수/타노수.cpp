#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	string str;
	cin >> str;
	string ans;
	function<void(string, int, int)> dfs = [&](string pivot, int depth, int len)
		{
			if (depth == b)
			{
				ans = max(ans, pivot);
				return;
			}
			dfs(pivot.substr(0, len /2), depth + 1, len / 2);
			dfs(pivot.substr(len / 2, pivot.size()), depth + 1, len / 2);
		};
	dfs(str, 0, (1 << a));
	cout << ans;
	return 0;
}