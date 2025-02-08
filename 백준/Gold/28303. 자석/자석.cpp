#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, ans = LLONG_MIN;
	cin >> n >> k;
	vector<ll>v(n + 3, 0), t1(n + 3, 0), t2(n + 3, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		if (i == 1)
		{
			t1[2] = v[1] - k;
			t2[2] = v[1] + k;
			continue;
		}
		ans = max({ ans, t1[i] - v[i], v[i] - t2[i] });
		t1[i + 1] = max(t1[i] - k, v[i] - k);
		t2[i + 1] = min(t2[i] + k, v[i] + k);
	}
	cout << ans;
	return 0;
}