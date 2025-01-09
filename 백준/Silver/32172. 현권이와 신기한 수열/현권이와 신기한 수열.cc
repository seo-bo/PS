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
	unordered_set<ll>ss;
	ss.insert(0);
	vector<ll>dp(100000, 0);
	for (int i = 1; i <= n; ++i)
	{
		ll pivot = dp[i - 1] - i;
		if (ss.find(pivot) != ss.end() || pivot < 0)
		{
			dp[i] = dp[i - 1] + i;
		}
		else
		{
			dp[i] = pivot;	
		}
		ss.insert(dp[i]);
	}
	cout << dp[n];
	return 0;
}