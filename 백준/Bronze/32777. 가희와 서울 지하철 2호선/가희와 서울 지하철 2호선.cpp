#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int i = (b - a + 43) % 43;
		int j = (a - b + 43) % 43;
		if (i < j)
		{
			cout << "Inner circle line";
		}
		else if (i > j)
		{
			cout << "Outer circle line";
		}
		else
		{
			cout << "Same";
		}
		cout << '\n';
	}
	return 0;
}