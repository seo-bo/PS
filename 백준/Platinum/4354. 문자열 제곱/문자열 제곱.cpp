#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		string a;
		cin >> a;
		if (a == ".")
		{
			break;
		}
		int len = a.size();
		vector<int>pattern(len, 0);
		auto fail = [&]
			{
				int left = 0;
				for (int right = 1; right < len; ++right)
				{
					while (left > 0 && a[left] != a[right])
					{
						left = pattern[left - 1];
					}
					if (a[left] == a[right])
					{
						pattern[right] = ++left;
					}
				}
			};
		fail();
		int pivot = len - pattern[len - 1];
		if (len % pivot)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << len / pivot << '\n';
		}
	}
	return 0;
}