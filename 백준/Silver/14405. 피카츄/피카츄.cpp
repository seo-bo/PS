#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string>v = { "pi","ka","chu" };
	string str;
	cin >> str;
	for (auto& i : v)
	{
		int j = 0;
		while ((j = str.find(i)) != string::npos)
		{
			str.replace(j, i.length(), i.length(), ' ');
		}
	}
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	if (str.empty())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}