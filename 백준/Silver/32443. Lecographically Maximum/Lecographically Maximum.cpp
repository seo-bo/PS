#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<int>bits(31, 0);
	for (auto& i : v)
	{
		for (int k = 0; k < 31; ++k)
		{
			if (i & (1 << k))
			{
				bits[k]++;
			}
		}
	}
	vector<ll>ans(n, 0);
	for (int i = 30; i >= 0; --i)
	{
		if (!bits[i])
		{
			continue;
		}
		for (int k = 0; k < bits[i]; ++k)
		{
			ans[k] += (1LL << i);
		}
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}