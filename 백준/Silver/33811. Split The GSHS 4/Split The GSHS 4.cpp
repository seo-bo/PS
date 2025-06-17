#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<int>dp(n + 5, 0);
	for (int i = 0; i < n - 3; ++i)
	{
		int temp = 0;
		if (str[i] == 'S' && str[i + 1] == 'S' && str[i + 2] == 'H' && str[i + 3] == 'S')
		{
			temp++;
		}
		if (str[i] == 'G' && str[i + 1] == 'S' && str[i + 2] == 'H' && str[i + 3] == 'S')
		{
			temp--;
		}
		dp[i + 1] = max(dp[i] + temp, temp);
		ans = max(ans, dp[i + 1]);
	}
	cout << ans;
	return 0;
}