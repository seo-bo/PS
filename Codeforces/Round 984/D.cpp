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
		int n = 0, m = 0;
		cin >> n >> m;
		vector<string>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		ll ans = 0;
		for (int i = 0; i < min(n, m) / 2; ++i)
		{
			string pivot;
			int up = i, down = n - i - 1, left = i, right = m - i - 1;
			for (int j = left; j <= right; ++j)
			{
				pivot += v[up][j];
			}
			for (int j = up + 1; j <= down; ++j)
			{
				pivot += v[j][right];
			}
			if (down != up)
			{
				for (int j = right - 1; j >= left; --j)
				{
					pivot += v[down][j];
				}
			}
			if (left != right)
			{
				for (int j = down - 1; j >= up + 1; --j)
				{
					pivot += v[j][left];
				}
			}
			if (pivot.size() >= 4)
			{
				string one = pivot + pivot.substr(0, 3);
				for (int j = 0; j < pivot.size(); ++j)
				{
					if (one[j] == '1' && one[j + 1] == '5' && one[j + 2] == '4' && one[j + 3] == '3')
					{
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
