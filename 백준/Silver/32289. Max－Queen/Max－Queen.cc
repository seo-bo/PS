#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	ll pivot = 5 + 4 * (m - 2);
	ll ans = pivot * (n - 1) + (m - 1);
	cout << ans;
	return 0;
}