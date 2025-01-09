#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>dp;
	dp[1] = 1;
	ll cur = 1;
	for (int i = 2;; ++i)
	{
		cur += i;
		if (cur > 200000)
		{
			break;
		}
		dp[cur] = i;
	}
	int n = 0;
	cin >> n;
	if (n == 2 || n == 5)
	{
		cout << -1;
		return 0;
	}
	vector<int>ans;
	int len = n;
	while (len)
	{
		auto it = dp.upper_bound(len);
		--it;
		auto [a, b] = *it;
		len -= a;
		for (int i = 0; i < b; ++i)
		{
			ans.push_back(0);
		}
		if (ans.size() < n)
		{
			ans.push_back(1);
		}
	}
	if (ans.size() > n)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (i < ans.size())
		{
			cout << ans[i] << ' ';
		}
		else
		{
			cout << 1 << ' ';
		}
	}
	return 0;
}