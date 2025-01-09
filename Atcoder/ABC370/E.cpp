#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n + 1, 0), prefix(n + 1, 0);
	unordered_map<ll, ll>dp;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	dp[0] = 1;
	ll a = 0, dpsum = 1, ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll non = prefix[i] - k; // 안되는거 찾기
		ans = (dpsum - dp[non] + MOD) % MOD; // 현재 dp합에서 안되는거 빼주기
		dp[prefix[i]] = (dp[prefix[i]] + ans) % MOD; // 갱신
		dpsum = (dpsum + ans) % MOD; // dp합 갱신
	}
	cout << ans;
	return 0;
}
