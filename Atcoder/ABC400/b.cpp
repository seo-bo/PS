#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll maxi = 1e9;
	ll n = 0, m = 0;
	cin >> n >> m;
	ll res = 1, pivot = 1;
	for (ll i = 1; i <= m; ++i)
	{
		if (pivot > maxi / n)
		{
			cout << "inf";
			return 0;
		}
		pivot *= n;
		if (res > maxi - pivot)
		{
			cout << "inf";
			return 0;
		}
		res += pivot;
	}
	cout << res;
	return 0;
}
