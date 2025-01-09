#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	getline(cin, str);
	auto it = str.find("(");
	if (it == string::npos)
	{
		cout << str << '\n';
		cout << "-";
	}
	else
	{
		cout << str.substr(0, it - 1) << '\n';
		cout << str.substr(it + 1, str.size() - it - 2);
	}
	return 0;
}