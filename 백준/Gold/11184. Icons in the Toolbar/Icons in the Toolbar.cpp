#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 어쩌피 정렬된 상태로 제공되면, 그냥 적절히 분할하면 되는거 아님??
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(2 * n, 0), prefix(2 * n + 3, 0), pref(2 * n + 3, 0);
	for (int i = 0; i < 2 * n; ++i)
	{
		cin >> v[i];
		prefix[i + 1] = prefix[i] + v[i];
		if (!(i % 2))
		{
			pref[i + 2] = pref[i] + v[i];
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i <= n; ++i)
	{
		ll res = prefix[i] + pref[2 * n] - pref[2 * i];
		ans = min(ans, res * (v[0] + v[i]));
	}
	cout << ans;
	return 0;
}