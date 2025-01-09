#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int d = 0, p = 0;
	cin >> d >> p;
	vector<int>dp(d + 1, INT_MIN);
	dp[0] = INT_MAX;
	for (int i = 1; i <= p; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		for (int j = d; j >= a; --j)
		{
			if (dp[j - a] != INT_MIN)
			{
				dp[j] = max(dp[j], min(dp[j - a], b));
			}
		}
	}
	cout << dp[d];
	return 0;
}