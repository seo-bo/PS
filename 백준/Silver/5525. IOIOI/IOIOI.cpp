#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, cnt = 0, ans = 0;
	string str;
	cin >> n >> m >> str;
	for (int i = 0; i < m - 2; ++i)
	{
		if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I')
		{
			cnt++;
			if (cnt >= n)
			{
				ans++;
			}
			i++;
		}
		else
		{
			cnt = 0;
		}
	}
	cout << ans;
	return 0;
}