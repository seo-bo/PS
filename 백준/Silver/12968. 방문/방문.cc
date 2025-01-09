#include <bits/stdc++.h>
using namespace std;
typedef long double lb;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	if (a % 2 && b % 2)
	{
		cout << ((c > 1) ? 0 : 1);
		return 0;
	}
	cout << 1;
	return 0;
}