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
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, k = 0, x = 0;
	cin >> n >> k >> x;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<vector<int>>dp(k + 1, vector<int>(n * x + 1, INT_MIN));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		auto [a, b] = v[i];
		for (int j = k; j >= 1; --j)
		{
			for (int aa = j * x; aa >= a; --aa)
			{
				if (dp[j - 1][aa - a] != INT_MIN)
				{
					dp[j][aa] = max(dp[j][aa], dp[j - 1][aa - a] + b);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= k * x; ++i)
	{
		if (dp[k][i] != INT_MIN)
		{
			ans = max(ans, i * dp[k][i]);
		}
	}
	cout << ans;
	return 0;
}