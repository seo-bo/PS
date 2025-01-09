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
		ll k = 0, l1 = 0, l2 = 0, r1 = 0, r2 = 0;
		cin >> k >> l1 >> r1 >> l2 >> r2;
		ll ans = 0, power = 1;
		while (power <= r2)
		{
			ll left = (l2 + power - 1) / power, right = r2 / power;
			ll low = max(l1, left), high = min(r1, right);
			if (low <= high)
			{
				ans += high - low + 1;
			}
			if (power > r2 / k)
			{
				break;
			}
			power *= k;
		}
		cout << ans << '\n';
	}
	return 0;
}
