#include <bits/stdc++.h>
#define OFF 1000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, pivot = 0;
	cin >> n;
	vector<ti>v(n);
	vector<vector<int>>dp(1002, vector<int>(2002, INT_MAX));
	dp[0][OFF] = 0;
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
		pivot = max(pivot, a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < pivot; ++i)
	{
		for (int j = 0; j <= 2 * OFF; ++j)
		{
			if (dp[i][j] < INT_MAX)
			{
				if (j > 0)
				{
					dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + 1);
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
					if (2 * OFF)
					{
						dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
					}
				}
			}
		}
		for (auto& [_, a, b] : v)
		{
			if (i + 1 == _)
			{
				for (int j = a + 1 + OFF; j < b + OFF; ++j)
				{
					dp[_][j] = INT_MAX;
				}
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i <= 2000; ++i)
	{
		ans = min(ans, dp[pivot][i]);
	}
	cout << (ans == INT_MAX ? -1 : ans);
	return 0;
}