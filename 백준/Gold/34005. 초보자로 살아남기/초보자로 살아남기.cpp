#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[601][101][2][7];
// 시간, SP, 스트라이크 쿨타임, 박치기 쿨타임

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll T = 0;
	cin >> T;
	while (T--)
	{
		ll A = 0, B = 0, C = 0, p = 0;
		cin >> A >> B >> C >> p;
		ll left = 1, right = 600, ans = -1;
		auto cal = [&](ll mid)
			{
				memset(dp, -1, sizeof(dp));
				function<ll(ll, ll, ll, ll)> dfs = [&](ll time, ll sp, ll c, ll d)
					{
						if (time > mid)
						{
							return 0LL;
						}
						if (dp[time][sp][c][d] != -1)
						{
							return dp[time][sp][c][d];
						}
						ll res = max(dfs(time + 1, min(sp + 1, 100LL), max(c - 1, 0LL), max(d - 1, 0LL)) + 100, dfs(time + 1, min(100LL, sp + 8), max(c - 1, 0LL), max(d - 1, 0LL)) + A);
						if (sp >= 10)
						{
							if (!c)
							{
								res = max(res, dfs(time + 2, sp - 8, 1, max(d - 2, 0LL)) + B);
							}
							if (!d)
							{
								res = max(res, dfs(time + 2, sp - 8, max(c - 2, 0LL), 6) + C);
							}
						}
						return dp[time][sp][c][d] = res;
					};
				ll pp = dfs(1, 100, 0, 0);
				return pp >= p;
			};
		while (left <= right)
		{
			ll mid = (left + right) >> 1;
			if (cal(mid))
			{
				ans = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}