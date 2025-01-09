#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<string>token;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	size_t ans = 1;
	string str = "";
	cin >> num >> str;
	vector<char>v;
	for (int i = 0; i < str.size(); ++i)
	{
		if (v.size() && v.back() == '(' && str[i] == ')')
		{
			v.pop_back();
		}
		else if (v.size() && v.back() == ')' && str[i] == '(')
		{
			v.pop_back();
		}
		else
		{
			v.push_back(str[i]);
		}
		ans = max(v.size(), ans);
	}
	if (!v.size())
	{
		cout << ans;
	}
	else
	{
		cout << -1;
	}
	return 0;
}