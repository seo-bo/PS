#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<ll> v(n + 1);
	vector<vector<map<ll, ll>>>dp(n + 1, vector<map<ll, ll>>(n + 1));
	vector<ll> ans(n);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	ans[0] = n;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k < j; ++k)
			{
				ll dif = v[j] - v[k];
				ll cnt = (i == 2) ? 1 : dp[k][i - 2][dif];
				dp[j][i - 1][dif] = (dp[j][i - 1][dif] + cnt) % MOD;
				ans[i - 1] = (ans[i - 1] + cnt) % MOD;
			}
		}
	}
	for (auto & i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
