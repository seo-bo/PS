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
		int n = 0, ans = 0;
		cin >> n;
		for (int i = 5; i <= n; i *= 5)
		{
			ans += n / i;
		}
		cout << ans << '\n';
	}
	return 0;
}