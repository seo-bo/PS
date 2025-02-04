#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	for (int _ = 1; _ <= T; ++_)
	{
		ll x = 0, y = 0;
		cin >> x >> y;
		ll pivot = 1;
		while (1)
		{
			ll p = llabs(x) + llabs(y), sum = pivot * (pivot + 1) / 2;
			if (sum >= p && (sum - p) % 2 == 0)
			{
				break;
			}
			pivot++;
		}
		string ans;
		for (; pivot >= 1; --pivot)
		{
			if (llabs(x) > llabs(y))
			{
				if (x > 0)
				{
					ans += 'E';
					x -= pivot;
				}
				else
				{
					ans += 'W';
					x += pivot;
				}
			}
			else
			{
				if (y > 0)
				{
					ans += 'N';
					y -= pivot;
				}
				else
				{
					ans += 'S';
					y += pivot;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		cout << format("Case #{}: {}\n", _, ans);
	}
	return 0;
}