#include <bits/stdc++.h>
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
	ll n = 0, p = 0, q = 0, r = 0, s = 0;
	cin >> n >> p >> q >> r >> s;
	vector<ll>dp(40, 0);
	cin >> dp[1];
	for (int i = 1; i <= 10; ++i)
	{
		dp[2 * i] = p * dp[i] + q;
		dp[2 * i + 1] = r * dp[i] + s;
	}
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += dp[i];
	}
	cout << sum;
	return 0;
}