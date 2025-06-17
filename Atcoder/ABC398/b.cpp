#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>mm;
	for (int i = 0; i < 7; ++i)
	{
		int temp = 0;
		cin >> temp;
		mm[temp]++;
	}
	for (auto& [a, b] : mm)
	{
		if (b >= 3)
		{
			for (auto& [c, d] : mm)
			{
				if (a != c && d >= 2)
				{
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
	return 0;
}
