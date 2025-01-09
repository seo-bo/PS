#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n = 0, ans = 1;
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		ans *= i;
	}
	cout << ans;
	return 0;
}