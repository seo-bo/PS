#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		int Lleft = 1, Lright = n - 1;
		int Rleft = 0, Rright = n - 2;
		while (Lleft < n)
		{
			if (v[Lleft - 1] == v[Lleft])
			{
				Lleft++;
			}
			else
			{
				break;
			}
		}
		while (Lright >= 0)
		{
			if (v[0] == v[Lright])
			{
				Lright--;
			}
			else
			{
				break;
			}
		}
		while (Rright >= 0)
		{
			if (v[Rright + 1] == v[Rright])
			{
				Rright--;
			}
			else
			{
				break;
			}
		}
		while (Rleft < n)
		{
			if (v[n - 1] == v[Rleft])
			{
				Rleft++;
			}
			else
			{
				break;
			}
		}
		int ans1 = (Lleft == n && Lright == -1) ? 0 : Lright - Lleft + 1;
		int ans2 = (Rleft == n && Rright == -1) ? 0 : Rright - Rleft + 1;
		cout << min(ans1, ans2) << '\n';
	}
	return 0;
}
