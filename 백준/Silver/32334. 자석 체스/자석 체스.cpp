#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0;
	cin >> n >> d;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0)), prefix(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
			prefix[i][j] = v[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}
	pii win = make_pair(-1, -1);
	pii rem = make_pair(-1, -1);
	int mini = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (!v[i][j])
			{
				int r1 = max(1, i - d), r2 = min(n, i + d);
				int c1 = max(1, j - d), c2 = min(n, j + d);
				int pivot = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
				if (!pivot)
				{
					if (win.first == -1 || win.first > i || (win.first == i && win.second > j))
					{
						win = make_pair(i, j);
					}
				}
				else
				{
					if (pivot < mini)
					{
						mini = pivot;
						rem = make_pair(i, j);
					}
					else if (pivot == mini)
					{
						if (rem.first > i || (rem.first == i && rem.second > j))
						{
							rem = make_pair(i, j);
						}
					}
				}
			}
		}
	}
	if (win.first != -1)
	{
		cout << win.first << ' ' << win.second;
	}
	else
	{
		cout << rem.first << ' ' << rem.second << '\n';
		cout << mini;
	}
	return 0;
}