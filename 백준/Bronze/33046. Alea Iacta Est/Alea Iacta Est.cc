#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	ll sum1 = a + b, sum2 = c + d;
	ll p1 = (sum1 - 1) % 4 + 1;
	cout << ((p1 - 1) + (sum2 - 1)) % 4 + 1;
	return 0;
}