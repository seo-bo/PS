#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	int len = str.size();
	int a = 0, b = 0;
	for (int i = 0; i < len;)
	{
		if (str[i] == 'b')
		{
			a++;
			i += 7;
		}
		else
		{
			b++;
			i += 8;
		}
	}
	if (a > b)
	{
		cout << "bigdata?";
	}
	else if (a < b)
	{
		cout << "security!";
	}
	else
	{
		cout << "bigdata? security!";
	}
	return 0;
}