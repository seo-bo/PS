#include <bits/stdc++.h>
#include <unordered_map>
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	ll result = 0;
	if (str[0] == 'd')
	{
		result = 10;
	}
	else
	{
		result = 26;
	}
	int siz = str.length();
	for (int i = 1; i < siz; ++i)
	{
		switch (str[i])
		{
			case 'd':
			{
				if (str[i - 1] == 'd')
				{
					result = (result * 9) % MOD;
				}
				else
				{
					result = (result * 10) % MOD;
				}
				break;
			}
			case 'c':
			{
				if (str[i - 1] == 'c')
				{
					result = (result * 25) % MOD;
				}
				else
				{
					result = (result * 26) % MOD;
				}
				break;
			}
		}
	}
	cout << result;
	return 0;
}