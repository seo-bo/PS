#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	b += c + d;
	if (a <= b || a <= 240)
	{
		cout << "high speed rail";
	}
	else
	{
		cout << "flight";
	}
	return 0;
}