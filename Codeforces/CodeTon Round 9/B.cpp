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
		string a, b;
		cin >> a;
		bool check = false;
		int len = a.size();
		for (int i = 0; i < len - 1; ++i)
		{
			if (a[i] == a[i + 1])
			{
				b = a.substr(i, 2);
				check = true;
				break;
			}
		}
		if (!check)
		{
			for (int i = 0; i < len - 2; ++i)
			{
				if (a[i] != a[i + 1] && a[i + 1] != a[i + 2] && a[i] != a[i + 2])
				{
					b = a.substr(i, 3);
					check = true;
					break;
				}
			}
		}
		if (check)
		{
			cout << b << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
	return 0;
}
