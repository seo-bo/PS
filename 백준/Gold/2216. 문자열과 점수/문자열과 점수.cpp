#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	string A, B;
	cin >> A >> B;
	int alen = A.size(), blen = B.size();
	vector<vector<int>>dp(alen + 1, vector<int>(blen + 1, -1e8));
	function<int(int, int)> dfs = [&](int i, int j)
		{
			if (i == alen && j == blen)
			{
				return 0;
			}
			if (dp[i][j] != -1e8)
			{
				return (int)dp[i][j];
			}
			int res = -1e8;
			if (i < alen)
			{
				res = max(res, dfs(i + 1, j) + b);
			}
			if (j < blen)
			{
				res = max(res, dfs(i, j + 1) + b);
			}
			if (i < alen && j < blen)
			{
				int cost = (A[i] == B[j]) ? a : c;
				res = max(res, dfs(i + 1, j + 1) + cost);
			}
			return dp[i][j] = res;
		};
	cout << dfs(0, 0);
	return 0;
}