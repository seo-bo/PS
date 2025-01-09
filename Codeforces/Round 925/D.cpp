#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		map<pii, ll>mm;
		int n = 0, x = 0, y = 0;
		ll ans = 0;
		cin >> n >> x >> y;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			int xx = temp % x, yy = temp % y;
			ans += mm[make_pair((x - xx) % x, yy)]; // 맞네;; 오른쪽 식으로 넘기면 x를 나눠줘야하는구나
			mm[make_pair(xx, yy)]++;
		}
		cout << ans << '\n';
	}
	return 0;
}
