#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto sv = [&]
		{
			vector<string>ok;
			string str, temp;
			cin >> str;
			int cnt = 0;
			for (auto& i : str)
			{
				temp += i;
				if (++cnt == 3)
				{
					cnt = 0;
					ok.push_back(temp);
					temp = "";
				}
			}
			return ok;
		};
	vector<string>A = sv(), B = sv();
	int alen = A.size(), blen = B.size();
	vector<vector<int>>dp(alen + 1, vector<int>(blen + 1, -1));
	function<int(int, int)> dfs = [&](int i, int j)
		{
			if (i == alen || j == blen)
			{
				return 0;
			}
			if (dp[i][j] != -1)
			{
				return dp[i][j];
			}
			int res = max(dfs(i + 1, j), dfs(i, j + 1));
			if (A[i] == B[j])
			{
				res = max(res, dfs(i + 1, j + 1) + 1);
			}
			return dp[i][j] = res;
		};
	cout << dfs(0, 0);
	return 0;
}