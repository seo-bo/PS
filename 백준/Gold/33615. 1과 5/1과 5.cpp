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
		string str;
		cin >> str;
		if (str.back() == '5')
		{
			cout << 0 << ' ' << 5 << '\n';
			continue;
		}
		ll sum = 0, one = -1, five = -1;
		for (int i = 0; i < (int)str.size(); ++i)
		{
			int pivot = str[i] - '0';
			sum += str[i] - '0';
			if (pivot == 1 && one == -1)
			{
				one = i + 1;
			}
			if (pivot == 5 && five == -1)
			{
				five = i + 1;
			}
		}
		if (sum % 3 == 0)
		{
			cout << 0 << ' ' << 3 << '\n';
			continue;
		}
		if (five == -1)
		{
			if (sum % 2)
			{
				cout << 1 << ' ' << 11 << '\n';
			}
			else
			{
				cout << 0 << ' ' << 11 << '\n';
			}
		}
		else
		{
			if ((sum - 1) % 3 == 0)
			{
				cout << one << ' ' << 3 << '\n';
			}
			else
			{
				cout << five << ' ' << 3 << '\n';
			}
		}
	}
}