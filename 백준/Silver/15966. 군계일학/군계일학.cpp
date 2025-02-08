#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void) // O(N)이 필요한거같은데
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<int>v(1000001, 0);
	vector<int>dp(1000001, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		dp[v[i]] = max(dp[v[i]], dp[v[i] - 1] + 1);
		ans = max(ans, dp[v[i]]);
	}
	cout << ans;
	// 집합과 맵으로 푸는 방법은 없나?
	return 0;
}