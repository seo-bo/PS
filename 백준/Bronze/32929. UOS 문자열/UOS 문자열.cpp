#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n % 3 == 1)
	{
		cout << 'U';
	}
	else if (n % 3 == 2)
	{
		cout << 'O';
	}
	else
	{
		cout << 'S';
	}
	return 0;
}