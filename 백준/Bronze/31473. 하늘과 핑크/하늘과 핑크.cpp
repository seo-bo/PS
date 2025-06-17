#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, a = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		a += temp;
	}
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		b += temp;
	}
	cout << b << ' ' << a << '\n';
	return 0;
}