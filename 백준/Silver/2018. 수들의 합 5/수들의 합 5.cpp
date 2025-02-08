#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, sum = 1, ans = 0;
	cin >> n;
	int left = 1, right = 1;
	while (right <= n)
	{
		if (sum > n)
		{
			sum -= left;
			left++;
		}
		else
		{
			if (sum == n)
			{
				ans++;
			}
			right++;
			sum += right;
		}
	}
	cout << ans;
	return 0;
}