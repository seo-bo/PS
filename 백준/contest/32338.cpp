#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 음수 처리..?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int t = 0, n = 0;
	cin >> t >> n;
	vector<tl>v(t);
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(202, -1));
	dp[0][100] = 0;
	for (auto& [a, b, c] : v)
	{
		for (int i = n; i >= b; --i)
		{
			for (int j = -100; j <= 100; ++j)
			{
				if (j - a < -100 || j - a > 100)
				{
					continue;
				}
				if (dp[i - b][j - a + 100] != -1)
				{
					dp[i][j + 100] = max(dp[i][j + 100], dp[i - b][j - a + 100] + c);
				}
			}
		}
	}
	ll ans1 = 0, ans2 = 0;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = -100; j <= 100; ++j)
		{
			if (dp[i][j + 100] == -1)
			{
				continue;
			}
			ll temp = 0;
			(j == 0) ? temp = 2 * dp[i][j + 100] : temp = dp[i][j + 100];// 2배인가 아닌가
			if (temp > ans2)
			{
				ans2 = temp;
				ans1 = j;
			}
			else if (temp == ans2) // 절댓값 비교 , 같으면 양으로
			{
				if (llabs(j) < llabs(ans1) || (llabs(j) == llabs(ans1) && j > ans1))
				{
					ans1 = j;
				}
			}
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
