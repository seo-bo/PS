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
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		cout << a + min(b, c) - 1 << '\n';
	}
	return 0;
}