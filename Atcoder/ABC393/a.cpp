#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str1, str2;
	cin >> str1 >> str2;
	if (str1 == "sick" && str2 == "fine")
	{
		cout << 2;
	}
	else if (str1 == "fine" && str2 == "sick")
	{
		cout << 3;
	}
	else if (str1 == "sick" && str2 == "sick")
	{
		cout << 1;
	}
	else
	{
		cout << 4;
	}
	return 0;
}
