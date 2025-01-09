#include <bits/stdc++.h>
#include <unordered_set>
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
	int t = 0, w = 0;
	cin >> t >> w;
	vector<int>v(t + 1);
	for (int i = 1; i <= t; ++i)
	{
		cin >> v[i];
	}
	int ans = 0;
	vector<vector<vector<int>>>dp(t + 1, vector<vector<int>>(w + 1, vector<int>(3, 0)));
	dp[1][0][1] = (v[1] == 1), dp[1][1][2] = (v[1] == 2);
	ans = max(dp[1][0][1], dp[1][1][2]);
	for (int i = 2; i <= t; ++i) // 시간
	{
		dp[i][0][1] = dp[i - 1][0][1] + (v[i] == 1);
		for (int j = 1; j <= w; ++j) // 최대 움직인 횟수
		{
			// i번 시간에 j번 움직였고, 1번 나무에 있다
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + (v[i] == 1);
			dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + (v[i] == 2);
			ans = max({ dp[i][0][1],dp[i][j][1],dp[i][j][2] });
		}
	}
	cout << ans;
	return 0;
}