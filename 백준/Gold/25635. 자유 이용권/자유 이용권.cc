#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, maxi = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		sum += temp;
		maxi = max(maxi, temp);
	}
	sum -= maxi;
	if (sum >= maxi - 1)
	{
		cout << sum + maxi;
	}
	else
	{
		cout << sum + sum + 1;
	}
	return 0;
}