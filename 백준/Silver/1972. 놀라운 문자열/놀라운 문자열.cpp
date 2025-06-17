#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	while (getline(cin, str))
	{
		if (str == "*")
		{
			break;
		}
		auto sv = [&]()
			{
				int len = str.size();
				for (int i = 1; i < len; ++i)
				{
					set<string>s;
					for (int j = 0; j + i < len; ++j)
					{
						string temp = "";
						temp += str[j];
						temp += str[j + i];
						if (s.find(temp) != s.end())
						{
							return false;
						}
						s.insert(temp);
					}
				}
				return true;
			};
		bool flag = sv();
		cout << format("{} is ", str);
		if (!flag)
		{
			cout << "NOT ";
		}

		cout << "surprising.\n";
	}
	return 0;
}