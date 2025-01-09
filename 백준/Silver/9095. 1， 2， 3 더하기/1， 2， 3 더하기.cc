#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll>dp(11);
	for (int i = 1; i <= 3; ++i)
	{
		dp[i] = 1;
	}
	for (int i = 2; i <= 10; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			if (i - j >= 0)
			{
				dp[i] += dp[i - j];
			}
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}