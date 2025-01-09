#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	pll dp = make_pair(LLONG_MAX, LLONG_MAX);
	dp.first = 0;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		pll temp = make_pair(LLONG_MAX, LLONG_MAX);
		if (dp.first <= a)
		{
			temp.first = min(temp.first, dp.first + b);
		}
		if (dp.second <= a)
		{
			temp.second = min(temp.second, dp.second + b);
		}
		temp.second = min(temp.second, dp.first);
		dp = temp;
	}
	if (dp == make_pair(LLONG_MAX, LLONG_MAX))
	{
		cout << "Zzz";
	}
	else
	{
		cout << "Kkeo-eok";
	}
	return 0;
}