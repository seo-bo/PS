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
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, ans =0;
		cin >> n;
		while (n >= 4)
		{
			n -= 4;
			ans++;
		}
		cout << ans + n / 2 << '\n';
	}
	return 0;
}
