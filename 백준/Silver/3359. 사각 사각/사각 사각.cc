#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<ll, ll>>dp(n + 1, { 0,0 });
	vector<pair<ll, ll>>v(n + 1, { 0,0 });
	cin >> v[1].first >> v[1].second;
	dp[1].first = v[1].first;
	dp[1].second = v[1].second;
	for (int i = 2; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
		// 첫변을 고르고, 최댓값을 찾아야하니까
		dp[i].first = v[i].first + (max(dp[i - 1].first + llabs(v[i - 1].second - v[i].second), dp[i - 1].second + llabs(v[i - 1].first - v[i].second)));
		dp[i].second = v[i].second + (max(dp[i - 1].first + llabs(v[i - 1].second - v[i].first), dp[i - 1].second + llabs(v[i - 1].first - v[i].first)));
	}
	cout << max(dp[n].first, dp[n].second);
	return 0;
}