#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
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
	ll n = 0, h = 0;
	cin >> n >> h;
	vector<ll>dp(h + 1, 0);
	vector<ll>v(n + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[j] <= i)
			{
				dp[i] = (dp[i] + dp[i - v[j]]) % MOD;
			}		
		}
	}
	cout << dp[h];
	return 0;
}