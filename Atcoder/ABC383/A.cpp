#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>a(n), b(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i];
	}
	ll ans = 0, pre = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(0LL, ans - (a[i] - pre));
		ans += b[i];
		pre = a[i];
	}
	cout << ans;
	return 0;
}
