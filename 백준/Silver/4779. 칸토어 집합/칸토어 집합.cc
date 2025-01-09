#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void cantor(int num)
{
	if (!num)
	{
		cout << '-';
		return;
	}
	cantor(num - 1);
	int size = pow(3, num - 1);
	for (int i = 0; i < size; ++i)
	{
		cout << ' ';
	}
	cantor(num - 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int get = 0;
	while (cin >> get)
	{
		cantor(get);
		cout << "\n";
	}
	return 0;
}