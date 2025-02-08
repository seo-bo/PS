#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	if (str.substr(0, 3) == "555")
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}