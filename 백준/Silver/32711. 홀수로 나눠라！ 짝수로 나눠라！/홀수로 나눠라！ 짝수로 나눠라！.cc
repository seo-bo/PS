#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	ll sum = 0;
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	if (sum % 2)
	{
		cout << 1;
		return 0;
	}
	auto check = [&](ll a, ll b)
		{
			if (a == 0 || b == 0)
			{
				return;
			}
			if ((a % 2 == 0) && (b % 2 == 0))
			{
				cout << 1;
				exit(0);
			}
		};
	ll a = sum - v.back(), b = v.back();
	check(a, b);
	for (int i = n - 2; i >= 0; --i)
	{
		a -= v[i];
		b += v[i];
		check(a, b);
	}
	cout << 0;
	return 0;
}