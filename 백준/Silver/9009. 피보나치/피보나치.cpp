#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>dp(2);
	vector<int>fibo(1);
	dp[0] = 0, dp[1] = fibo[0] = 1;
	int idx = 2;
	while (1)
	{
		ll sum = dp[idx - 1] + dp[idx - 2];
		if (sum >= 1000000000)
		{
			break;
		}
		dp.push_back(sum);
		fibo.push_back(sum);
		idx++;
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		deque<int>ans;
		for (auto it = fibo.rbegin(); it != fibo.rend(); ++it)
		{
			if (!n)
			{
				break;
			}
			if (n >= *it)
			{
				n -= *it;
				ans.push_front(*it);
			}
		}
		while (!ans.empty())
		{
			cout << ans.front() << ' ';
			ans.pop_front();
		}
		cout << '\n';
	}
	return 0;
}