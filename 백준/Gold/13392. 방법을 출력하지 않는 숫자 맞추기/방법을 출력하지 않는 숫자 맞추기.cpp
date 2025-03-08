#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string A, B;
	cin >> A >> B;
	vector<int>now, nxt;
	for (auto& i : A)
	{
		now.push_back(i - '0');
	}
	for (auto& i : B)
	{
		nxt.push_back(i - '0');
	}
	vector<vector<int>>dp(n, vector<int>(10, -1));
	function<int(int, int)> dfs = [&](int idx, int turn)
		{
			if (idx == n)
			{
				return 0;
			}
			if (dp[idx][turn] != -1)
			{
				return dp[idx][turn];
			}
			int res = 1e8;
			int nw = (now[idx] + turn) % 10;
			if (nw == nxt[idx])
			{
				res = min(res, dfs(idx + 1, turn));
			}
			int a = 10, b = 10;
			if (nw < nxt[idx])
			{
				a = nxt[idx] - nw;
				b = nw + 10 - nxt[idx];
			}
			else if (nw > nxt[idx])
			{
				a = 10 - nw + nxt[idx];
				b = nw - nxt[idx];
			}
			res = min({ res, dfs(idx + 1,turn) + b, dfs(idx + 1, (turn + a) % 10) + a });
			return dp[idx][turn] = res;
		};
	cout << dfs(0, 0);
	return 0;
}