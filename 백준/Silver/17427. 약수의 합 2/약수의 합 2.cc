#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += (n / i) * i;
	}
	cout << ans;
	return 0;
}