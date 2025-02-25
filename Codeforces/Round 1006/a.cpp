#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll a = 0, b = 0, c = 0, ans = 0;
		cin >> a >> b >> c;
		b = abs(b);
		for (; ans < a && b; ++ans)
		{
			b -= min(b, c);
		}
		if (!b)
		{
			cout << ans << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
	return 0;
}
