#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n < 4)
	{
		cout << 0;
		return 0;
	}
	ll a = n / 4, b = n % 4, ans = 2 * a * a + a * b - 2 * a;
	if (!b)
	{
		ans++;
	}
	cout << ans;
	return 0;
}