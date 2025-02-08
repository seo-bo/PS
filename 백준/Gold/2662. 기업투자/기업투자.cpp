#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(1, 0));
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < m; ++j)
		{
			int temp = 0;
			cin >> temp;
			v[a].push_back(temp);
		}
	}
	vector<int>dp(n + 1, 0);
	vector<vector<pii>>pos(n + 1);
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = n; k >= 1; --k)
			{
				if (k - j < 0)
				{
					break;
				}
				if (dp[k] < dp[k - j] + v[j][i])
				{
					vector<pii>temp = pos[k - j];
					if (!temp.empty() && temp.back().second == i)
					{
						continue;
					}
					dp[k] = dp[k - j] + v[j][i];
					temp.push_back(make_pair(j, i)); // j원 가격 투자에서 i번째 회사를 골랐다.
					pos[k] = temp;
				}
			}
		}
	}
	vector<int>ans(m + 1, 0);
	for (auto& [a, b] : pos[n])
	{
		ans[b] += a;
	}
	cout << dp[n] << '\n';
	for (int i = 1; i <= m; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}