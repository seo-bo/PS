#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	string str;
	cin >> str;
	string left, right;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '*')
		{
			if (i == 0)
			{
				left = "^";
				right = str.substr(i + 1);
			}
			else if (i == str.length() - 1)
			{
				left = str.substr(0, i);
				right = "^";
			}
			else
			{
				left = str.substr(0, i);
				right = str.substr(i + 1);
			}
			break;
		}
	}
	int llen = left.length();
	int rlen = right.length();
	while (T--)
	{
		string temp;
		cin >> temp;
		int tlen = temp.length();
		if (tlen < llen + rlen)
		{
			cout << "NE" << '\n';
			continue;
		}
		if (left == "^" && right == "^")
		{
			cout << "DA" << '\n';
		}
		else if (left == "^")
		{
			if (right == temp.substr(tlen - rlen))
			{
				cout << "DA" << "\n";
			}
			else
			{
				cout << "NE" << '\n';
			}
		}
		else if (right == "^")
		{
			if (left == temp.substr(0, llen))
			{
				cout << "DA" << "\n";
			}
			else
			{
				cout << "NE" << '\n';
			}
		}
		else
		{
			if (left == temp.substr(0, llen) && right == temp.substr(tlen - rlen))
			{
				cout << "DA" << "\n";
			}
			else
			{
				cout << "NE" << '\n';
			}
		}
	}
	return 0;
}