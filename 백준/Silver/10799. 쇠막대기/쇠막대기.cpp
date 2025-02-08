#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<char>v;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	ll result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ')')
		{
			v.pop_back();
		}
		else if (str[i] == '(')
		{
			if (str[i + 1] == ')')
			{
				result += v.size();
				i++;
			}
			else
			{
				result++;
				v.push_back('(');
			}
		}
	}
	cout << result;
	return 0;
}