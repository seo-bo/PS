#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	vector<int>dp(n, 0);
	for (int i = 0; i < m; ++i)
	{
		vector<int>temp(n, 0);
		for (int j = 0; j < n; ++j)
		{
			int cost = (a[j] == b[i]);
			if (j - 1 >= 0)
			{
				temp[j] = max(temp[j], dp[j - 1] + cost);
			}
			if (j + 1 < n)
			{
				temp[j] = max(temp[j], dp[j + 1] + cost);
			}
		}
		dp = move(temp);
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}