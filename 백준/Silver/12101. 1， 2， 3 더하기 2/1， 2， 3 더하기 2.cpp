#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	if (k > 274)
	{
		cout << -1;
		return 0;
	}
	vector<int>v;
	int cnt = 0;
	function<void(int)> dfs = [&](int sum)
		{
			if (sum == n)
			{
				cnt++;
				if (k == cnt)
				{
					int siz = v.size();
					for (int i = 0; i < siz; ++i)
					{
						cout << v[i];
						if (i < siz - 1)
						{
							cout << '+';
						}
					}
					exit(0);
				}
				return;
			}
			for (int i = 1; i <= 3; ++i)
			{
				if (sum + i <= n)
				{
					v.push_back(i);
					dfs(sum + i);
					v.pop_back();
				}
			}
		};
	dfs(0);
	cout << -1;
	return 0;
}