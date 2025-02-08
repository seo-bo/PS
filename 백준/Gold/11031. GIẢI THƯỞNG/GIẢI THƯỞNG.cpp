#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	while (cin >> n)
	{
		vector<vector<vector<ll>>>dp(n + 1, vector<vector<ll>>(4, vector<ll>(4, 0)));
		dp[0][0][0] = 1; // 일수 , 지각, 연속 결석
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= 1; ++j)
			{
				for (int k = 0; k <= 2; ++k)
				{
					dp[i][j][0] += dp[i - 1][j][k];
					if (j > 0)
					{
						dp[i][j][0] += dp[i - 1][j - 1][k];
					}
					if (k < 2)
					{
						dp[i][j][k + 1] += dp[i - 1][j][k];
					}
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i <= 1; ++i)
		{
			for (int j = 0; j <= 2; ++j)
			{
				ans += dp[n][i][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}