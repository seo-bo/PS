#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= 500; ++i)
		{
			for (int j = 1; j <= 500; ++j)
			{
				if (i == n - j)
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
