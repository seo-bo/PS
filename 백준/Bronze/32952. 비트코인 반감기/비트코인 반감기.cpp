#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ull r = 0, k = 0, m = 0;
	cin >> r >> k >> m;
	ull pivot = 0;
	if (k)
	{
		pivot = m / k;
	}
	ull ans = 0;
	if (pivot >= 64)
	{
		pivot = 0;
	}
	else
	{
		ull temp = 0;
		if (pivot < 64)
		{
			temp = ((ull)1LL << pivot);
			ans = r / temp;
		}
	}
	cout << ans;
	return 0;
}
