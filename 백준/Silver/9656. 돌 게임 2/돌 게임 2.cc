#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dp[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	dp[1] = false;
	dp[2] = true;
	dp[3] = false;
	for (int i = 4; i <= num; ++i)
	{
		dp[i] = !dp[i - 1] | !dp[i - 3];
	}
	if (!dp[num])
	{
		cout << "CY";
	}
	else
	{
		cout << "SK";
	}
	return 0;
}