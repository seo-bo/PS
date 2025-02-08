#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n == 2)
	{
		cout << 1;
	}
	else if (n == 3)
	{
		cout << 3;
	}
	else
	{
		cout << 3 * n - 4;
	}
	return 0;
}