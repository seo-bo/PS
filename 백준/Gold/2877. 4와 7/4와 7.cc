#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, temp = 0, len = 1;
	cin >> n;
	for (ll i = 1;; ++i)
	{
		if (temp + (1LL << i) >= n)
		{
			break;
		}
		temp += (1LL << i);
		len = i + 1;
	}
	string str(len, '4');
	ll cur = n - temp - 1;
	for (ll i = len - 1; i >= 0; --i)
	{
		if (cur & (1LL << i))
		{
			str[len - i - 1] = '7';
		}
	}
	cout << str;
	return 0;
}