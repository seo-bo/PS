#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, ans = 1;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<int>dp(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1;
		for (int j = 1; j < i; ++j)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	vector<int>(n + 1, 0).swap(dp);
	for (int i = n; i >= 1; --i)
	{
		dp[i] = 1;
		for (int j = n; j > i; --j)
		{
			if (v[i] < v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
	return 0;
}