#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, d = 0;
	cin >> n >> d;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	char input = (n < 0) ? 'L' : 'R';
	n = llabs(n);
	ll div = gcd(n, d);
	n /= div, d /= div;
	ll a = n / d, b = n % d, idx = -1;
	deque<char>ans;
	for (ll i = 0; i <= 62; ++i)
	{
		ll pivot = (1LL << i);
		if (pivot == d)
		{
			idx = i;
		}
		ans.push_back('U');
	}
	if (idx == -1)
	{
		cout << -1;
		return 0;
	}
	ans.pop_back();
	for (ll i = 62; i >= 0; --i)
	{
		ll pivot = (1LL << i);
		while (a >= pivot)
		{
			ans.push_back(input);
			a -= pivot;
		}
		ans.push_back('D');
	}
	ll x1 = 2;
	while (b)
	{
		ll up = d / x1;
		while (b >= up)
		{
			ans.push_back(input);
			b -= up;
		}
		ans.push_back('D');
		x1 <<= 1;
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i;
	}
	return 0;
}