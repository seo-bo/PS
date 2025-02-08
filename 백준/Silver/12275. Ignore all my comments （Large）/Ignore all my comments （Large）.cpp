#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	vector<char>s;
	vector<char>result;

	while (getline(cin, str))
	{
		for (int i = 0; i < str.length(); ++i)
		{
			if (i + 1 < str.length() && str[i] == '/' && str[i + 1] == '*')
			{
				s.push_back('/');
				s.push_back('*');
				++i;
			}
			else if (s.empty())
			{
				result.push_back(str[i]);
			}
			else if (i + 1 < str.length() && str[i] == '*' && str[i + 1] == '/')
			{
				s.pop_back();
				s.pop_back();
				++i;
			}
		}
		if (s.empty())
		{
			result.push_back('\n');
		}
	}
	cout << "Case #1:" << "\n";
	for (auto& i : result)
	{
		cout << i;
	}
	return 0;
}