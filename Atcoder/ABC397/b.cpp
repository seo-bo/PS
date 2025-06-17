#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	int ans = len;
	for (int i = 0; i < len; ++i)
	{
		if (i + 1 < len && str[i] == 'i' && str[i + 1] == 'o')
		{
			ans -= 2;
			++i;
		}
	}
	cout << ans;
	return 0;
}
