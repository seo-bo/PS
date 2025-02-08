#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<char, int>mm;
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	mm['a'] = a, mm['b'] = b, mm['c'] = c, mm['d'] = d;
	string str;
	cin >> str;
	if (str.size() == 1)
	{
		if (str.back() == 'a' && mm['a'])
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
		return 0;
	}
	if (str.size() == 2)
	{
		cout << "No";
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			if (str[i] != 'a' || !mm[str[i]])
			{
				cout << "No";
				return 0;
			}
			mm[str[i]]--;
			continue;
		}
		if (i == n - 1)
		{
			if (str[i] != 'a' || !mm[str[i]])
			{
				cout << "No";
				return 0;
			}
		}
		if (i >= 1)
		{
			if (str[i] == str[i - 1] || !mm[str[i]])
			{
				cout << "No";
				return 0;
			}
			mm[str[i]]--;
		}
	}
	cout << "Yes";
	return 0;
}