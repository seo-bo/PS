#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	function<string(int)>solve = [&](int n) ->string
		{
			if (n == 0)
			{
				return "0";
			}
			if (n == 1)
			{
				return "1";
			}
			if (n % -2 == 0)
			{
				return solve(n / -2) + "0";
			}
			else
			{
				if (n > 0)
				{
					return solve(n / -2) + "1";
				}
				else
				{
					return solve((n - 1) / -2) + "1";
				}
			}
		};
	cout << solve(n);
	return 0;
}