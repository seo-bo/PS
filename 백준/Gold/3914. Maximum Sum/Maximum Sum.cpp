#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v;
	for (int i = 0; i < n; ++i)
	{
		vector<int>temp;
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int t = 0;
			cin >> t;
			temp.push_back(t);
		}
		v.push_back(temp);
	}
	vector<int>dp(1010, 0);
	for (int i = 0; i < n; ++i)
	{
		vector<int>temp = dp;
		for (auto& j : v[i])
		{
			for (int k = 1; k <= j; ++k)
			{
				temp[j] = max(temp[j], dp[k] + j);
			}
		}
		dp = move(temp);
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}