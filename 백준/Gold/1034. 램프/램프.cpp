#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	map<string, int>mm;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		mm[str]++;
	}
	int x = 0;
	cin >> x;
	int ans = 0;
	for (auto& [a, b] : mm)
	{
		int temp = x;
		for (auto& i : a)
		{
			if (i == '0')
			{
				temp--;
			}
		}
		if (temp < 0 || temp % 2)
		{
			continue;
		}
		ans = max(ans, b);
	}
	cout << ans;
	return 0;
}