#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>A(k + 1), B(k + 1), C(k + 1);
	for (int i = 1; i <= k; ++i)
	{
		cin >> A[i] >> B[i] >> C[i];
	}
	vector<ll>dp(m + 5, 0);
	for (int i = m; i >= 0; --i)
	{
		ll pivot = dp[i + 1];
		for (int j = 1; j <= k; ++j)
		{
			ll day = i + A[j];
			if (day > m)
			{
				continue;
			}
			ll sum = 0;
			for (int z = day; z <= m; z += B[j])
			{
				sum += C[j];
				ll pp = sum + dp[z];
				pivot = max(pp, pivot);
			}
		}
		dp[i] = pivot;
	}
	cout << dp[0] * n;
	return 0;
}