#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>w(n + 1), e(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> e[i];
	}
	vector<ll>dp(n + 1, -1);
	function<ll(int)> dfs = [&](int idx) // 분할점 ~ y는 무조건 같이 보기
		{
			if (idx == 0)
			{
				return 0LL;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			ll res = LLONG_MAX / 4, a = 0, b = 0;
			for (int i = idx; i >= 1; --i)
			{
				a = max(a, w[i]);
				b = max(b, e[i]);
				res = min(res, dfs(i - 1) + a * b);
			}
			return dp[idx] = res;
		};
	cout << dfs(n);
	return 0;
}