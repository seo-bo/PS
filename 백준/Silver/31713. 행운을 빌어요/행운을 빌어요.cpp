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
		int a = 0, b = 0, ans = 0;
		cin >> a >> b;
		for (; a * 4 < b; ++a)
		{
			++ans;
		}
		if (a * 3 > b)
		{
			ans += a * 3 - b;
		}
		cout << ans << '\n';
	}
	return 0;
}