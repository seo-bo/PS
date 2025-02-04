#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll left = 0, right = 1e10;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll a = mid, b = mid;
		for (auto& i : v)
		{
			ll nom = i;
			ll pivot = nom / 2;
			ll p = min(pivot, b);
			b -= p;
			nom -= 2 * p;
			a -= nom;
		}
		if (a == 0 && b == 0)
		{
			cout << "YES";
			return 0;
		}
		else if (a + b > 0)
		{
			right = mid - 1;
		}
		else if (a + b < 0)
		{
			left = mid + 1;
		}
	}
	cout << "NO";
	return 0;
}