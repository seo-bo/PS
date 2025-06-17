#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int x = 0, y = 0;
	cin >> x >> y;
	vector<int>dp(y + 3, 0);
	dp[y - 1] = 1;
	for (int i = y - 2; i >= x; --i)
	{
		for (int j = i + 1; j <= y; ++j)
		{
			if (gcd(i, j) == 1)
			{
				dp[i] |= (dp[j] + 1) % 2;
			}
		}
	}
	cout << ((dp[x]) ? "khj20006" : "putdata");
	return 0;
}