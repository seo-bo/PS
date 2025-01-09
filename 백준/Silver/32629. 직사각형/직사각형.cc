#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--) // 중간에 가깝게
	{
		ll a = 0;
		cin >> a;
		ll w1 = max(1LL, (ll)floor(sqrt(((long double)a))));
		ll h1 = (a + w1 - 1) / w1;
		ll ans1 = 2 * (w1 + h1);
		ll w2 = w1 + 1;
		ll h2 = (a + w2 - 1) / w2;
		ll ans2 = 2 * (w2 + h2);
		cout << min(ans1, ans2) << '\n';
	}
	return 0;
}