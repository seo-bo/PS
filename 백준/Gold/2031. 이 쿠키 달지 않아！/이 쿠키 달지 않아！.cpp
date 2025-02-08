#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 이게 정해일지도?..
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll t = 0, n = 0, d = 0, k = 0;
	cin >> t >> n >> d >> k;
	vector<ll>v(n, 0), effect(n + 1, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	vector<vector<ll>>dp(k + 1, vector<ll>(n + 1, 0));
	for (int i = 0; i < n; ++i)
	{
		auto it = lower_bound(v.begin(), v.end(), v[i] - d + 1);
		effect[i + 1] = distance(it, v.begin() + i) + 1;
	}
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - effect[j]] + effect[j]);
		}
	}
	cout << dp[k][n];
	return 0;
}