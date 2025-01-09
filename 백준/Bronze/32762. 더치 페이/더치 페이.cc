#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	lb ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		lb b = 0;
		cin >> a >> b;
		ans += b;
	}
	cout << fixed << setprecision(12) << ans / n;
	return 0;
}