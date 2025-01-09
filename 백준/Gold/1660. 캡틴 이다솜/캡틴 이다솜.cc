#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v, dp(n + 1, INT_MAX);
	ll prefix = 0, pivot = 0;
	for (int i = 1;; ++i)
	{
		prefix += i;
		if (v.empty())
		{
			pivot = 1;
		}
		else
		{
			pivot = v.back() + prefix;
		}
		if (pivot > n)
		{
			break;
		}
		v.push_back(pivot);
	}
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (auto& k : v)
		{
			if (k > i)
			{
				break;
			}
			dp[i] = min(dp[i], dp[i - k] + 1);
		}
	}
	cout << dp[n];
	return 0;
}
