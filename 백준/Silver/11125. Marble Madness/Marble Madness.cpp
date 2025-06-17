#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (b % 2)
		{
			cout << "0.00 1.00\n";
		}
		else
		{
			cout << "1.00 0.00\n";
		}
	}
	return 0;
}