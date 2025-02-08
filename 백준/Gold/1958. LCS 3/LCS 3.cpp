#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B, C;
	cin >> A >> B >> C;
	int alen = A.size(), blen = B.size(), clen = C.size();
	vector<vector<vector<int>>>dp(101, vector<vector<int>>(101, vector<int>(101, -1)));
	function<int(int, int, int)> dfs = [&](int a, int b, int c)
		{
			if (a == alen || b == blen || c == clen)
			{
				return 0;
			}
			if (dp[a][b][c] != -1)
			{
				return dp[a][b][c];
			}
			if (A[a] == B[b] && B[b] == C[c])
			{
				dp[a][b][c] = dfs(a + 1, b + 1, c + 1) + 1;
			}
			else
			{
				dp[a][b][c] = max({ dfs(a + 1,b,c),dfs(a,b + 1,c),dfs(a,b,c + 1) });
			}
			return dp[a][b][c];
		};
	cout << dfs(0, 0, 0);
	return 0;
}