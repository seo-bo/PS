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
	string str, up, down;
	ll u = 1, d = 1;
	cin >> str;
	bool check = false;
	bool mulcheck = false;
	for (auto& i : str)
	{
		if (i == '(')
		{
			check = true;
		}
		else if (i == '.')
		{
			mulcheck = true;
		}
		if (check && '0' <= i && i<= '9')
		{
			down += i;
			if (mulcheck)
			{
				d *= 10;
			}
		}
		else if ('0' <= i && i <= '9')
		{
			up += i;
			down += i;
			if (mulcheck)
			{
				u *= 10;
				d *= 10;
			}
		}
	}
	//cout << up << '\n' << down << '\n' << u << '\n' << d << '\n';
	ll uu = stoll(up);
	ll dd = stoll(down);
	if (!check)
	{
		ll GCD = gcd(u, uu);
		cout << uu / GCD << '/' << u / GCD;
	}
	else
	{
		dd -= uu;
		d -= u;
		ll GCD = gcd(dd, d);
		cout << dd / GCD << '/' << d / GCD;
	}
	return 0;
}