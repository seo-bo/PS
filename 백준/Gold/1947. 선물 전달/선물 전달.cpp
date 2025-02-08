#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll pp = 1, pre = 0, cur = 0;
	for (ll i = 2; i <= n; ++i)
	{
		cur = ((i - 1) * (pp + pre)) % MOD;
		pp = pre, pre = cur;
	}
	cout << cur;
	return 0;
}