#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int x = 0, y = 0;
	for (int i = 1; i <= 9; ++i)
	{
		cout << format("? A {}", i) << endl;
		int temp = 0;
		cin >> temp;
		if (temp)
		{
			x = i;
			break;
		}
	}
	for (int i = 1; i <= 9; ++i)
	{
		cout << format("? B {}", i) << endl;
		int temp = 0;
		cin >> temp;
		if (temp)
		{
			y = i;
			break;
		}
	}
	cout << format("! {}", x + y) << endl;
	return 0;
}