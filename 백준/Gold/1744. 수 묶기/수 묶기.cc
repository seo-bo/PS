#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll ans = 0;
	int n = 0;
	cin >> n;
	deque<int>minus;
	deque<int>plus;
	deque<int>zero;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a > 0)
		{
			plus.push_back(a);
		}
		else if (a < 0)
		{
			minus.push_back(a);
		}
		else
		{
			zero.push_back(a);
		}
	}
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end());
	while (minus.size() >= 2)
	{
		ll a = minus.front();
		minus.pop_front();
		ll b = minus.front();
		minus.pop_front();
		ans += a * b;
	}
	if (minus.size() == 1)
	{
		if (zero.empty())
		{
			ans += (ll)minus.front();
		}
	}
	while (plus.size() >= 2)
	{
		ll a = plus.back();
		plus.pop_back();
		ll b = plus.back();
		plus.pop_back();
		if (a + b > a * b)
		{
			ans += a + b;
			break;
		}
		ans += a * b;
	}
	while (!plus.empty())
	{
		ans += (ll)plus.back();
		plus.pop_back();
	}
	cout << ans;
	return 0;
}