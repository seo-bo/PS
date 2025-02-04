#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>base(1 << 10, 0);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		int mask = 0;
		for (auto& i : str)
		{
			mask |= (1 << (i - '0'));
		}
		base[mask]++;
	}
	ll ans = 0;
	for (int i = 0; i < (1 << 10); ++i)
	{
		for (int j = i; j < (1 << 10); ++j)
		{
			int pivot = i | j;
			if (__builtin_popcount(pivot) == k)
			{
				if (i == j)
				{
					ans += (ll)base[i] * (base[i] - 1) / 2LL;
				}
				else
				{
					ans += (ll)base[i] * base[j];
				}
			}
		}
	}
	cout << ans;
	return 0;
}