#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000
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
	string str;
	cin >> str;
	if (str[0] == '0')
	{
		cout << 0;
		return 0;
	}
	int n = str.length();
	vector<ll>dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 1; i < n; ++i)
	{
		int o = str[i] - '0';
		int t = (str[i - 1] - '0') * 10 + o;
		if (o >= 1 && o <= 9)
		{
			dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
		}
		if (t >= 10 && t <= 26)
		{
			dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
		}
	}
	cout << dp[n];
	return 0;
}