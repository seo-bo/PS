#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void) // a는 250 배수, m은 15배수
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v) // 625 ? 250 * 15 = 3750 / 625 * 6
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		i = (a * b) / 3750;
	}
	ll st = 0, ed = 0;
	cin >> st >> ed;
	st = (st + 5) / 6, ed = ed / 6;
	vector<ll>dp(ed + 1, 0);
	dp[0] = 1;
	for (auto& i : v)
	{
		if (i > ed)
		{
			continue;
		}
		for (int j = ed; j >= i; --j)
		{
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}
	ll ans = 0;
	for (int i = st; i <= ed; ++i)
	{
		ans = (ans + dp[i]) % MOD;
	}
	cout << ans;
	return 0;
}