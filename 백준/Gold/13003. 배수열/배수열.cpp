#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
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
	int n = 0, l = 0;
	cin >> n >> l;
	vector<vector<ll>>dp(l + 1, vector<ll>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		dp[1][i] = 1;
	}
	unordered_map<int, unordered_set<int>>mm;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (!(i % j))
			{
				mm[i].insert(j);
				if ((i / j) != j)
				{
					mm[i].insert(i / j);
				}
			}
		}
	}
	for (int i = 2; i <= l; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (auto& k : mm[j])
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans = (ans + dp[l][i]) % MOD;
	}
	cout << ans;
	return 0;
}