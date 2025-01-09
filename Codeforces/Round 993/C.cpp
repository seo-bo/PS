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
		ll m = 0, a = 0, b = 0, c = 0;
		cin >> m >> a >> b >> c;
		ll p1 = m, p2 = m, ans = 0;
		ll n1 = min(m, a);
		p1 -= n1, ans += n1;
		ll n2 = min(m, b);
		p2 -= n2, ans += n2;
		ll n3 = min(p1, c);
		c -= n3, ans += n3;
		ll n4 = min(p2, c);
		c -= n4, ans += n4;
		cout << ans << '\n';
	}
	return 0;
}
