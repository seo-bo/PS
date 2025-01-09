#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	if (k >= n)
	{
		cout << 0;
		return 0;
	}
	ll p = k * n;
	if (p % 2)
	{
		cout << n - 1;
	}
	else
	{
		cout << n;
	}
	return 0;
}