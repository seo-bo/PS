#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	if (n == 2 && k == 1)
	{
		cout << 1 << ' ' << 2;
		return 0;
	}
	if (n == 1)
	{
		for (int i = 0; i < k; ++i)
		{
			cout << 1 << ' ';
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}