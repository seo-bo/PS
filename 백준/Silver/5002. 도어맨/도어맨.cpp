#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str;
	cin >> n >> str;
	int len = str.size();
	int a = 0, b = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == 'M')
		{
			if (abs(a + 1 - b) <= n)
			{
				a++;
				continue;
			}
			else
			{
				if (i + 1 < len && str[i + 1] == 'W')
				{
					str[i + 1] = 'M';
					b++;
					continue;
				}
				break;
			}
		}
		else if (str[i] == 'W')
		{
			if (abs(a - (b + 1)) <= n)
			{
				b++;
				continue;
			}
			else
			{
				if (i + 1 < len && str[i + 1] == 'M')
				{
					str[i + 1] = 'W';
					a++;
					continue;
				}
				break;
			}
		}
	}
	cout << a + b;
	return 0;
}