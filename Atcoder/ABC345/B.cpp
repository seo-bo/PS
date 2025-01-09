#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long temp = 0;
	cin >> temp;
	if (temp % 10 == 0 || temp % 10 < 0)
	{
		cout << temp / 10;
	}
	else
	{
		cout << (temp / 10) + 1;
	}
	return 0;
}
