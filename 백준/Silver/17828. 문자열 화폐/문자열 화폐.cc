#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0;
	cin >> n >> x;
	if (n > x || 26 * n < x)
	{
		cout << "!";
		return 0;
	}
	string ans = string(n, 'A');
	x -= n;
	for (int i = n - 1; i >= 0; --i)
	{
		if (x + 1 > 26)
		{
			ans[i] = 'Z';
			x -= 25;
		}
		else
		{
			ans[i] = x + 'A';
			break;
		}
	}
	cout << ans;
	return 0;
}