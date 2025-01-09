#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0;
	cin >> a >> b;
	cout << "SN " << a;
	if (b <= 26)
	{
		char p = 'A' + b - 1;
		cout << p;
	}
	else
	{
		b -= 26;
		for (char i = 'a'; i <= 'z'; ++i)
		{
			for (char j = 'a'; j <= 'z'; ++j)
			{
				if (b == 1)
				{
					cout << i << j;
					return 0;
				}
				b--;
			}
		}
	}
	return 0;
}