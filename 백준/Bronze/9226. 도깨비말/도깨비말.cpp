#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		string str;
		cin >> str;
		if (str == "#")
		{
			break;
		}
		int idx = str.size();
		unordered_set<char>s = { 'a','i','u','e','o' };
		for (int i = 0; i < str.size(); ++i)
		{
			if (s.find(str[i]) != s.end())
			{
				idx = i;
				break;
			}
		}
		for (int i = idx; i < str.size(); ++i)
		{
			cout << str[i];
		}
		for (int i = 0; i < idx; ++i)
		{
			cout << str[i];
		}
		cout << "ay\n";
	}
	return 0;
}