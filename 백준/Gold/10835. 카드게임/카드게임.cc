#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>A(n + 1, 0), B(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> B[i];
	}
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	function<int(int, int)> dfs = [&](int a, int b)
		{
			if (a > n || b > n)
			{
				return 0;
			}
			if (dp[a][b] != -1)
			{
				return dp[a][b];
			}
			int pivot = 0;
			if (B[b] < A[a])
			{
				pivot = max(pivot, dfs(a, b + 1) + B[b]);
			}
			pivot = max({ pivot, dfs(a + 1, b), dfs(a + 1,b + 1) });
			return dp[a][b] = pivot;
		};
	cout << dfs(1, 1);
	return 0;
}