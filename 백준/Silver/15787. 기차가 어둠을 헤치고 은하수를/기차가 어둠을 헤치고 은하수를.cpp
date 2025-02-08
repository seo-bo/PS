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
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n);
	for (int k = 0; k < m; ++k)
	{
		int temp = 0, i = 0, x = 0;
		cin >> temp >> i;
		i--;
		switch (temp)
		{
			case 1:
			{
				cin >> x;
				x--;
				v[i] |= (1LL << x);
				break;
			}
			case 2:
			{
				cin >> x;
				x--;
				v[i] &= ~(1LL << x);
				break;
			}
			case 3:
			{
				v[i] = (v[i] << 1) & ~(1 << 20);
				break;
			}
			case 4:
			{
				v[i] = (v[i] >> 1);
				break;
			}
		}
	}
	map<int, int>mm;
	for (auto& i : v)
	{
		mm[i]++;
	}
	cout << mm.size();
	return 0;
}