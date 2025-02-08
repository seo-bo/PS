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
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0;
		cin >> n;
		vector<ll>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		cin >> k;
		vector<ll>dp(10001);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = v[i]; j <= k; ++j)
			{
				dp[j] += dp[j - v[i]];
			}
		}
		cout << dp[k] << '\n';
	}
	return 0;
}