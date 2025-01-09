#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto judge = [&](char a)
		{
			int n = (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') ? 1 : 0;
			return n;
		};
	while (1)
	{
		string str;
		cin >> str;
		if (str == "end")
		{
			break;
		}
		if (str.length() <= 1)
		{
			if (judge(str[0]))
			{
				cout << '<' << str << "> is acceptable." << '\n';
			}
			else
			{
				cout << '<' << str << "> is not acceptable." << '\n';
			}
			continue;
		}
		if (str.length() <= 2)
		{
			if (judge(str[0]) || judge(str[1]))
			{
				if (str[0] == str[1])
				{
					if (str[0] == 'e' || str[1] == 'o')
					{
						cout << '<' << str << "> is acceptable." << '\n';
					}
					else
					{
						cout << '<' << str << "> is not acceptable." << '\n';
					}
				}
				else
				{
					cout << '<' << str << "> is acceptable." << '\n';
				}
			}
			else
			{
				cout << '<' << str << "> is not acceptable." << '\n';
			}
			continue;
		}
		bool check = true, v = false;
		for (int i = 0; i < str.length() - 2; ++i)
		{
			int a = judge(str[i]), b = judge(str[i + 1]), c = judge(str[i + 2]);
			if (a || b || c)
			{
				v = true;
			}
			if (a == b && b == c)
			{
				check = false;
			}
			if (str[i] == str[i + 1] || str[i + 1] == str[i + 2])
			{
				if (str[i + 1] != 'e' && str[i + 1] != 'o')
				{
					check = false;
				}
			}
		}
		if (check && v)
		{
			cout << '<' << str << "> is acceptable." << '\n';
		}
		else
		{
			cout << '<' << str << "> is not acceptable." << '\n';
		}
	}
	return 0;
}