#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, pre = 0;
		cin >> n;
		vector<int>ans(n + 1, 1);
		for (int i = 2; i <= n; ++i)
		{
			cout << "? 1" << ' ' << i << endl;
			int temp = 0;
			cin >> temp;
			if (temp)
			{
				if (!pre)
				{
					pre = temp;
					ans[i] = 1;
					for (int j = i - 1; j >= 1 && temp; --j)
					{
						ans[j] = 0;
						temp--;
					}
				}
				else if (pre == temp)
				{
					ans[i] = 0;
					pre = temp;
				}
				else if (pre < temp)
				{
					ans[i] = 1;
					pre = temp;
				}
			}
		}
		if (!pre)
		{
			cout << "! IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "! ";
			for (int i = 1; i <= n; ++i)
			{
				cout << ans[i];
			}
			cout << endl;
		}
	}
	return 0;
}
