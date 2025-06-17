#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str, rev;
	cin >> str;
	if (str == "1")
	{
		cout << "no";
		return 0;
	}
	rev = str;
	string ban = "347";
	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		if (ban.find(str[i]) != string::npos)
		{
			cout << "no";
			return 0;
		}
		if (str[i] == '6')
		{
			rev[i] = '9';
		}
		else if (str[i] == '9')
		{
			rev[i] = '6';
		}
	}
	reverse(rev.begin(), rev.end());
	ll a = stoll(str), b = stoll(rev);
	ll lim = max(a, b);
	for (ll i = 2; i * i <= lim; ++i)
	{
		if (a % i == 0 || b % i == 0)
		{
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
	return 0;
}