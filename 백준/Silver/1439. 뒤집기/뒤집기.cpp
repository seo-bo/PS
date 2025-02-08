#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	ll zero = 0, one = 0;
	if (str[0] == '0')
	{
		zero++;
	}
	else
	{
		one++;
	}
	for (int i = 1; i < str.length(); ++i)
	{
		if (str[i] != str[i - 1])
		{
			if (str[i] == '1')
			{
				one++;
			}
			else
			{
				zero++;
			}
		}
	}
	cout << min(one, zero);
	return 0;
}