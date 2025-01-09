#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, k = 0;
		cin >> n >> m >> k;
		string str;
		cin >> str;
		vector<int> dp(n + 2, -1);
		dp[0] = k;
		for (int i = 1; i <= n + 1; ++i)
		{
			if (str[i - 1] == 'C')
			{
				continue;
			}
			for (int j = 1; j <= m; ++j)
			{
				if (i >= j && (i == j || str[i - j - 1] == 'L'))
				{
					dp[i] = max(dp[i], dp[i - j]);
				}
			}
			if (i > 1 && str[i - 2] == 'W')
			{
				dp[i] = max(dp[i], dp[i - 1] - 1);
			}
		}
		cout << ((dp[n + 1] >= 0) ? "YES" : "NO") << '\n';
	}
	return 0;
}
