#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007;
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, cnt = 0;
	cin >> n >> m;
	vector<vector<ll>>v(m + 1), INT(m + 1), STR(m + 1);
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (!temp)
		{
			cnt++;
		}
		else
		{
			if (temp > 0)
			{
				INT[cnt].push_back(temp);
			}
			else
			{
				STR[cnt].push_back(-temp);
			}
		}
	}
	for (int i = 0; i <= m; ++i)
	{
		sort(INT[i].begin(), INT[i].end());
		sort(STR[i].begin(), STR[i].end());
	}
	vector<ll>dp(m + 2, -1);
	dp[0] = 0;
	ll ans = 0;
	for (int i = 0; i <= m; ++i)
	{
		vector<ll>now(m + 2, -1);
		for (int j = 0; j <= i; ++j)
		{
			if (dp[j] == -1)
			{
				continue;
			}
			int pivot = i - j;
			int intel = upper_bound(STR[i].begin(), STR[i].end(), j) - STR[i].begin();
			int stren = upper_bound(INT[i].begin(), INT[i].end(), pivot) - INT[i].begin();
			int p = intel + stren;
			now[j + 1] = max(now[j + 1], dp[j] + p);
			now[j] = max(now[j], dp[j] + p);
			ans = max(ans, dp[j] + p);
		}
		dp = now;
	}
	cout << ans;
	return 0;
}
