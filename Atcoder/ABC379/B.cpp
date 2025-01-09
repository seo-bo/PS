#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i <= n - m; ++i)
	{
		bool check = true;
		for (int j = 0; j < m; ++j)
		{
			if (str[i + j] == 'X')
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			ans++;
			for (int j = 0; j < m; ++j)
			{
				str[i + j] = 'X';
			}
		}
	}
	cout << ans;
	return 0;
}
