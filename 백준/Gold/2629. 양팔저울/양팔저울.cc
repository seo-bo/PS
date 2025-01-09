#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, t = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	vector<vector<bool>> dp(n + 1, vector<bool>(40001, false));
	dp[0][0] = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 40000; j >= 0; --j)
		{
			if (dp[i][j])
			{
				dp[i + 1][j] = true;
				if (j + v[i] <= 40000)
				{
					dp[i + 1][j + v[i]] = true;
				}
				dp[i + 1][abs(j - v[i])] = true;
			}
		}
	}
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp <= 40000 && dp[n][temp])
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}
	return 0;
}