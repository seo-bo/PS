#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str(n, '-');
	if (n % 2)
	{
		str[n / 2] = '=';
	}
	else
	{
		str[n / 2 - 1] = str[n / 2] = '=';
	}
	cout << str;
	return 0;
}
