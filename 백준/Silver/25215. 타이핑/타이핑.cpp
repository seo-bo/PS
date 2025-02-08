#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	vector<vector<ll>>dp(len + 3, vector<ll>(2, LLONG_MAX));
	dp[0][0] = 0;
	for (int i = 0; i < len; ++i)
	{
		int pivot = isupper(str[i]) ? 1 : 0;
		for (int j = 0; j < 2; ++j)
		{
			if (dp[i][j] == LLONG_MAX)
			{
				continue;
			}
			if (j == pivot) // 그대로 치기
			{
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			}
			else // 입력하고 별 or 마름모 누르고 입력 
			{
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 2);
				dp[i + 1][(j + 1) % 2] = min(dp[i + 1][(j + 1) % 2], dp[i][j] + 2);
			}
		}
	}
	cout << min(dp[len][0], dp[len][1]);
	return 0;
}