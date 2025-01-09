#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, ans = 0;
	lb r = 0;
	cin >> n >> r;
	while (n--)
	{
		vector<lb>temp(8);
		for (auto& i : temp)
		{
			cin >> i;
		}
		lb x = (temp[0] + temp[4]) / (lb)2.0;
		lb y = (temp[1] + temp[5]) / (lb)2.0;
		lb p1 = sqrt(x * x + y * y);
		lb xx = x - temp[0];
		lb yy = y - temp[1];
		lb p2 = sqrt(xx * xx + yy * yy);
		if (r >= (p1 - p2))
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}