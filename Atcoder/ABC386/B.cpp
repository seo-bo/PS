#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int ans = 0, idx = 0, len = str.size();
	while (idx < len)
	{
		if (idx + 1 < len && str[idx] == '0' && str[idx + 1] == '0')
		{
			idx += 2;
		}
		else
		{
			idx++;
		}
		ans++;
	}
	cout << ans;
	return 0;
}
