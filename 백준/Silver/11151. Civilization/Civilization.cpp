#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, pa = 0, pb = 0, pc = 0;
		cin >> n >> pa >> pb >> pc;
		vector<tp>v(n);
		for (auto& [a, b, c] : v)
		{
			cin >> a >> b >> c;
		}
		int ans = INT_MAX;
		for (int i = 1; i < (1 << n); ++i)
		{
			int a = 0, b = 0, c = 0, d = 0;
			for (int j = 0; j < n; ++j)
			{
				if (i & (1 << j))
				{
					auto [aa, bb, cc] = v[j];
					a += aa;
					b += bb;
					c += cc;
					d++;
				}
			}
			if (a >= pa && b >= pb && c >= pc)
			{
				ans = min(ans, d);
			}
		}
		if (ans == INT_MAX)
		{
			cout << "game over\n";
		}
		else
		{
			cout << ans << '\n';
		}
	}
	return 0;
}