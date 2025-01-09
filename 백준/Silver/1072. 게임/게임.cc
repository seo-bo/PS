#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll x = 0, y = 0;
	cin >> x >> y;
	ll z = y * 100 / x;
	ll low = 0, high = x, ans = x;
	if (z >= 99)
	{
		cout << -1;
		return 0;
	}
	while (low <= high)
	{
		ll mid = (low + high) / 2;
		if ((y + mid) * 100 / (x + mid) > z)
		{
			high = mid - 1;
			ans = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << ans;
	return 0;
}