#include <bits/stdc++.h>
#define MOD 9
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		ll sum = 0, len = str.size();
		vector<int>v(1, 0);
		for (auto& i : str)
		{
			v.push_back(i - '0');
		}
		vector<vector<int>>dp(len + 1, vector<int>(10, -1));
		function<int(int, int)> dfs = [&](int idx, int sum)
			{
				if (idx > len)
				{
					if (sum % 9)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				if (dp[idx][sum] != -1)
				{
					return dp[idx][sum];
				}
				int res = dfs(idx + 1, (sum + v[idx]) % 9);
				if (v[idx] == 2 || v[idx] == 3)
				{
					res |= dfs(idx + 1, (sum + (v[idx] * v[idx])) % 9);
				}
				return dp[idx][sum] = res;
			};
		if (dfs(1, 0))
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}
