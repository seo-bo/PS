#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	ll left = 0, right = sqrt(LLONG_MAX), mid = 0;
	ll ans = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid < sqrt(n))
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (mid * mid >= n)
	{
		cout << mid;
	}
	else
	{
		cout << mid + 1;
	}
	return 0;
}