#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0;
	cin >> a;
	ll res = 1;
	for (ll i = 1; ; ++i)
	{
		res *= i;
		if (res == a)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
