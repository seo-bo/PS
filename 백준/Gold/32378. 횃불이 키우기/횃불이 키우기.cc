#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	const ll p = 100000000000;
	const ll over = p + 100000000;
	ll n = 0, k = 0, s = 0;
	cin >> n >> k >> s;
	if (k > 36)
	{
		cout << "MEGA";
		return 0;
	}
	vector<ll>v(n + 1, 0), dp(k + 2, -over);
	dp[k] = s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll dead = 0;
		vector<ll>temp(k + 2, -over);
		for (int j = k; j >= 0; --j)
		{
			if (dp[j] > 0)
			{
				temp[j] = max(temp[j], dp[j] + v[i]);
			}
			if (j != k)
			{
				if (dp[j + 1] > 0)
				{
					temp[j] = max(temp[j], dp[j + 1] * 2);
				}
			}
			dead = max(dead, temp[j]);
			if (i == n)
			{
				ans = max(ans, temp[j]);
			}
		}
		if (dead == 0)
		{
			cout << -1;
			return 0;
		}
		if (dead >= over)
		{
			cout << "MEGA";
			return 0;
		}
		dp = move(temp);
	}
	if (ans <= 0)
	{
		cout << -1;
	}
	else if (ans > p)
	{
		cout << "MEGA";
	}
	else
	{
		cout << ans;
	}
	return 0;
}