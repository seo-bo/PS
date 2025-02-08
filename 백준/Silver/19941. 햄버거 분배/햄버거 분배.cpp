#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, k = 0, ans = 0;
	cin >> n >> k;
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == 'P')
		{
			int left = max(0, i - k), right = min(n - 1, i + k);
			for (int j = left; j <= right; ++j)
			{
				if (str[j] == 'H')
				{
					str[j] = 'X';
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}