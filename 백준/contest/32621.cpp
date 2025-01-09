#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	auto p = str.find('+');
	if (p == string::npos || p == 0 || p == str.size() - 1)
	{
		cout << "No Money";
		return 0;
	}
	string s1 = str.substr(0, p);
	string s2 = str.substr(p + 1);
	if (s1.empty() || s2.empty() || s1[0] == '0' || s2[0] == '0')
	{
		cout << "No Money";
		return 0;
	}
	for (auto& i : s1)
	{
		if (!('0' <= i && i <= '9'))
		{
			cout << "No Money";
			return 0;
		}
	}
	for (auto& i : s2)
	{
		if (!('0' <= i && i <= '9'))
		{
			cout << "No Money";
			return 0;
		}
	}
	if (s1 != s2)
	{
		cout << "No Money";
		return 0;
	}
	cout << "CUTE";
	return 0;
}
