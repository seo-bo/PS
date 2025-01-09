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
	int n = 0, k = 0, ans = 1;
	cin >> n >> k;
	for (int i = 2; i <= n; ++i)
	{
		ans *= i;
	}
	for (int i = 2; i <= n - k; ++i)
	{
		ans /= i;
	}
	for (int i = 2; i <= k; ++i)
	{
		ans /= i;
	}
	cout << ans;
	return 0;
}