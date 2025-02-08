#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0;
	cin >> q;
	while (q--)
	{
		ll a = 0, m = 0;
		cin >> a >> m;
		cout << (a * m * 1056) / (60 * 10000) << '\n';
	}
	return 0;
}