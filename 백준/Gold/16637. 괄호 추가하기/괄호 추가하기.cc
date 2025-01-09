#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	string str;
	cin >> n >> str;
	auto check = [&](ll a, char op, int b)
		{
			if (op == '+')
			{
				return a + b;
			}
			else if (op == '-')
			{
				return a - b;
			}
			else
			{
				return a * b;
			}
		};
	int ans = INT_MIN;
	function<void(int, ll)> dfs = [&](int i, int sum)
		{
			if (i == n - 1)
			{
				ans = max(ans, sum);
				return;
			}
			dfs(i + 2, check(sum, str[i + 1], str[i + 2] - '0'));
			if (i + 4 < n)
			{
				dfs(i + 4, check(sum, str[i + 1], check(str[i + 2] - '0', str[i + 3], str[i + 4] - '0')));
			}
		};
	dfs(0, str[0] - '0');
	cout << ans;
	return 0;
}