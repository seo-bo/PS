#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<ll>dp(n + 1, 0);
	dp[1] = v[1];
	ll total = v[1]; // 총합
	ll pivot = v[1]; // 더해졌는지 안더해졌는지 체크
	for (int i = 2; i <= n; ++i)
	{
		ll a = dp[i - 1]; // 뒤에 설 때
		ll b = dp[i - 1] + v[i] - total - pivot; // 앞에 설 때
		dp[i] = max(a, b);
		if (a < b)
		{
			pivot = v[i];
			total = v[i];
		}
		else
		{
			total += v[i];
		}
	}
	cout << dp[n];
	return 0;
}