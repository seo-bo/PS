#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n + 1, make_pair(0, 0));
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second < b.second;
		});
	vector<ll>dp(n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = dp[i - 1];
		for (int j = 0; j < i; ++j)
		{
			if (v[j].second <= v[i].first)
			{
				dp[i] = max(dp[i], dp[j] + (v[i].second - v[i].first));
			}
		}
	}
	cout << dp[n];
	return 0;
}