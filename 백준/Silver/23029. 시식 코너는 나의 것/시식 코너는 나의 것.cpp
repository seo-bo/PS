#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1, 0);
	vector<vector<ll>>dp(n + 1, vector<ll>(3, 0)); // 0 안먹음 , 1 먹음, 2 2번먹음
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	dp[1][0] = 0;
	dp[1][1] = v[1];
	dp[1][2] = 0;
	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
		dp[i][1] = dp[i - 1][0] + v[i];
		dp[i][2] = dp[i - 1][1] + v[i] / 2;
	}
	cout << max({ dp[n][0], dp[n][1], dp[n][2] });
	return 0;
}
