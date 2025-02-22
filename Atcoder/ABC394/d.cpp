#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	vector<char>s;
	for (auto& i : str)
	{
		if (i == '(' || i == '[' || i == '<')
		{
			s.push_back(i);
		}
		else
		{
			if (s.empty())
			{
				cout << "No";
				return 0;
			}
			if ((i == ')' && s.back() == '(') || (i == ']' && s.back() == '[') || (i == '>' && s.back() == '<'))
			{
				s.pop_back();
			}
			else
			{
				cout << "No";
				return 0;
			}
		}
	}
	if (s.empty())
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
