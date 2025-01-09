#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll w = 0, n = 0;
	cin >> w >> n;
	vector<ll>v(n + 1, 0), prefix(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	auto solve = [&](ll mid) -> bool // 하한선?
		{
			vector<bool> dp(n + 1, false);
			dp[0] = true;
			int l = 0, r = 0, cnt = 0;
			for (int i = 1; i <= n; ++i)
			{
				ll low = prefix[i] - w;
				ll high = prefix[i] - (w - mid);
				while (l < i && prefix[l] < low)
				{
					if (dp[l])
					{
						cnt--;
					}
					l++;
				}
				while (r < i && prefix[r] <= high)
				{
					if (dp[r])
					{
						cnt++;
					}
					r++;
				}
				dp[i] = (cnt > 0);
			}
			return dp[n];
		};
	ll left = 0, right = w, ans = w; // 분할?
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (solve(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans * ans;
	return 0;
}