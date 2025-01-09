#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int B = 0, R = 0, siz = 0;
	cin >> siz;
	string str = "";
	cin >> str;
	int k = 0;
	while (k < siz)
	{
		if (str[k] == 'R')
		{
			while (str[k] != 'B' && k < siz)
			{
				k++;
			}
			R++;
		}
		else
		{
			while (str[k] != 'R' && k < siz)
			{
				k++;
			}
			B++;
		}
	}
	k = 0;
	if (R < B)
	{
		int cnt = 1;
		while (k < siz)
		{
			if (str[k] == 'R')
			{
				while (str[k] != 'B' && k < siz)
				{
					k++;
				}
				cnt++;
			}
			else
			{
				k++;
			}
		}
		cout << cnt;
	}
	else
	{
		int cnt = 1;
		while (k < siz)
		{
			if (str[k] == 'B')
			{
				while (str[k] != 'R' && k < siz)
				{
					k++;
				}
				cnt++;
			}
			else
			{
				k++;
			}
		}
		cout << cnt;
	}
	return 0;
}