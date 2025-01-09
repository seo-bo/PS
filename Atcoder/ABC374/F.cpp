#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, k = 0, x = 0;
	cin >> n >> k >> x;
	vector<ll>v(n + 1, 0), prefix(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	vector<map<ll, ll>>dp(n + 1);
	dp[0][INT_MIN] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (auto& [a, b] : dp[i])
		{
			for (int j = 1; j <= k; ++j)
			{
				if (i + j > n)
				{
					break;
				}
				ll cost = max(a + x, v[i + j]);
				ll pivot = b + (cost * j - (prefix[i + j] - prefix[i]));
				if (dp[i + j].find(cost) == dp[i + j].end())
				{
					dp[i + j][cost] = pivot;
				}
				else
				{
					dp[i + j][cost] = min(dp[i + j][cost], pivot);
				}
			}
		}
	}
	ll ans = LLONG_MAX;
	for (auto& [a, b] : dp[n])
	{
		ans = min(ans, b);
	}
	cout << ans;
	return 0;
}
