#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, k = 0, ans = 0, add = 1;
		cin >> n >> k;
		if (k == 0)
		{
			cout << k << '\n';
			continue;
		}
		bool check = false;
		bool check2 = false;
		while (1)
		{
			if (!check)
			{
				k -= n;
				ans++;
				check = true;
			}
			if (check)
			{
				for (int i = 0; i < 2; ++i)
				{
					if (k <= 0)
					{
						check2 = true;
						break;
					}
					k -= (n - add);
					ans++;
				}
				add++;
			}
			if (k <= 0)
			{
				break;
			}
			if (check2)
			{
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
