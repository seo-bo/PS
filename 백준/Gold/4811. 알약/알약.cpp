#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);;
	while (1)
	{
		int n = 0;
		cin >> n;
		if (!n)
		{
			break;
		}
		vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, 0)); // 알약 반개, 알약 1개
		function<ll(int, int)> dfs = [&](int a, int b)->ll
			{
				if (a == -1)
				{
					return 0LL;
				}
				if (b == 0)
				{
					return 1LL;
				}
				return dp[a][b] ? dp[a][b] : dp[a][b] = dfs(a + 1, b - 1) + dfs(a - 1, b);
			};
		cout << dfs(0, n) << '\n';
	}
	return 0;
}