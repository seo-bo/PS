#include <bits/stdc++.h>
#define MOD 360000
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>base, per;
	auto pushing = [&](vector<int>& v)
		{
			vector<int>temp(n);
			for (auto& i : temp)
			{
				cin >> i;
			}
			sort(temp.begin(), temp.end());
			for (int i = 0; i < n; ++i)
			{
				if (i > 0)
				{
					v.push_back((temp[i] - temp[i - 1] + MOD) % MOD);
				}
			}
			v.push_back((temp[0] - temp[n - 1] + MOD) % MOD);
		};
	pushing(base);
	pushing(per);
	int len = base.size();
	for (int i = 0; i < len; ++i)
	{
		base.push_back(base[i]);
	}
	auto sv = [&]
		{
			int alen = per.size(), blen = base.size();
			int left = 0;
			vector<int>pattern(alen, 0);
			for (int right = 1; right < alen; ++right)
			{
				while (left > 0 && per[left] != per[right])
				{
					left = pattern[left - 1];
				}
				if (per[left] == per[right])
				{
					pattern[right] = ++left;
				}
			}
			left = 0;
			for (int right = 0; right < blen; ++right)
			{
				while (left > 0 && base[right] != per[left])
				{
					left = pattern[left - 1];
				}
				if (base[right] == per[left])
				{
					++left;
					if (left == alen)
					{
						return true;
					}
				}
			}
			return false;
		};
	if (sv())
	{
		cout << "possible";
	}
	else
	{
		cout << "impossible";
	}
	return 0;
}
