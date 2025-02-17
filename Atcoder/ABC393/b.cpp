#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size(), ans = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] != 'A')
		{
			continue;
		}
		for (int j = i + 1; j < len; ++j)
		{
			if (str[j] != 'B')
			{
				continue;
			}
			int pos = 2 * j - i;
			if (pos < len && str[pos] == 'C')
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
