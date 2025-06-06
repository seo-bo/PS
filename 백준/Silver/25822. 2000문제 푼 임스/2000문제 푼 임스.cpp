#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string _, temp;
	cin >> _;
	for (auto& i : _)
	{
		if (i == '.')
		{
			continue;
		}
		temp += i;
	}
	while (temp.size() < 3)
	{
		temp += '0';
	}
	int c = min(2, stoi(temp) / 99), n = 0;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	int cost = 0, ans = 0;
	vector<int>dp(c + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cost = max(cost, v[i]);
		vector<int>temp(c + 1, -1);
		temp[0] = 0;
		bool flag = (v[i] == 0);
		for (int j = 0; j <= c; ++j)
		{
			if (dp[j] == -1)
			{
				continue;
			}
			if (flag && j < c)
			{
				temp[j + 1] = max(temp[j + 1], dp[j] + 1);
				ans = max(temp[j + 1], ans);
			}
			else if (!flag)
			{
				temp[j] = dp[j] + 1;
				ans = max(temp[j], ans);
			}
		}
		dp = move(temp);
	}
	cout << ans << '\n' << cost;
	return 0;
}