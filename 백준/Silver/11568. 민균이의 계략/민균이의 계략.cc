#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0, ans = 1;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<int>dp(n + 1, 1);
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
			ans = max(ans, dp[i]);
		}
	}
	cout << ans;
	return 0;
}