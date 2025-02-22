#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int idx = 0;
	while (idx < (int)str.size() - 1)
	{
		if (str[idx] == 'W' && str[idx + 1] == 'A')
		{
			str[idx] = 'A';
			str[idx + 1] = 'C';
			if (idx > 0)
			{
				idx--;
			}
			else
			{
				idx++;
			}
		}
		else
		{
			idx++;
		}
	}
	cout << str;
	return 0;
}
