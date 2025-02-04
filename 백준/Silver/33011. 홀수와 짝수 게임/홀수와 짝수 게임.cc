#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n);
		int a = 0, b = 0;
		for (auto& i : v)
		{
			cin >> i;
			if (i % 2)
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		vector<vector<vector<vector<vector<int>>>>> dp(a + 1, vector<vector<vector<vector<int>>>>(b + 1, vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(3, -1)))));
		function<bool(int, int, int, int, int)> dfs = [&](int aa, int bb, int p1, int p2, int turn)
			{
				if (dp[aa][bb][p1][p2][turn] != -1)
				{
					return dp[aa][bb][p1][p2][turn];
				}
				bool check = false;
				int cur = ((turn == 1) ? p1 : p2);
				if (aa > 0)
				{
					if (cur == 0 || cur == 1)
					{
						int nxt1 = p1, nxt2 = p2;
						if (turn == 1)
						{
							nxt1 = 1;
						}
						else
						{
							nxt2 = 1;
						}
						if (!dfs(aa - 1, bb, nxt1, nxt2, 3 - turn))
						{
							check = true;
						}
					}
				}
				if (bb > 0)
				{
					if (cur == 0 || cur == 2)
					{
						int nxt1 = p1, nxt2 = p2;
						if (turn == 1)
						{
							nxt1 = 2;
						}
						else
						{
							nxt2 = 2;
						}
						if (!dfs(aa, bb - 1, nxt1, nxt2, 3 - turn))
						{
							check = true;
						}
					}
				}
				return dp[aa][bb][p1][p2][turn] = ((check) ? 1 : 0);
			};
		if (dfs(a, b, 0, 0, 1))
		{
			cout << "amsminn" << '\n';
		}
		else
		{
			cout << "heeda0528" << '\n';
		}
	}
	return 0;
}