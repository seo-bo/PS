#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	while (T--)
	{
		int n = 0;
		cin >> n;
		string str;
		cin >> str;
		str = '?' + str;
		vector<vector<int>>dp(n + 1, vector<int>(3, 0));
		for (int i = 1; i <= n; ++i) //R S P
		{
			if (str[i] == 'R')
			{
				dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
				dp[i][1] = 0;
				dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
			}
			else if (str[i] == 'S')
			{
				dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
				dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
				dp[i][2] = 0;
			}
			else if (str[i] == 'P')
			{
				dp[i][0] = 0;
				dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
				dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
			}
		}
		cout << max({ dp[n][0], dp[n][1], dp[n][2] });
	}
	return 0;
}
