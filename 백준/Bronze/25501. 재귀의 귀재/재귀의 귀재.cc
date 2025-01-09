#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		int ans = 0;
		function<int(int, int)> solve = [&](int left, int right) ->int
			{
				ans++;
				if (left >= right)
				{
					return 1;
				}
				else if (str[left] != str[right])
				{
					return 0;
				}
				else
				{
					return solve(left + 1, right - 1);
				}
			};
		cout << solve(0, str.length() - 1) << ' ';
		cout << ans << '\n';
	}
	return 0;
}