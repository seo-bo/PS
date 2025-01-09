#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		ll ans = LLONG_MAX;
		cin >> n >> m;
		vector<ll> A(n, 0);
		vector<ll> B(n, 0);
		vector<vector<ll>> dp(n, vector<ll>(2, 0));
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		reverse(A.begin(), A.end());
		for (int i = 0; i < n; ++i)
		{
			cin >> B[i];
		}
		reverse(B.begin(), B.end());
		dp[0][0] = A[0];
		dp[0][1] = B[0];
		for (int i = 1; i < n; ++i)
		{
			dp[i][0] = min(dp[i - 1][0] + A[i], dp[i - 1][1] + A[i]);
			dp[i][1] = min(dp[i - 1][0] + B[i], dp[i - 1][1] + B[i]);
		}
		for (int i = n - 1; i >= n - m; --i) // 마지막 사람은 무조건 A매수니까
		{
			ans = min(ans, dp[i][0]);
		}
		cout << ans << "\n";
	}
	return 0;
}
