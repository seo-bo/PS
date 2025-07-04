#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>prime(MAX + 5, 0);
	iota(prime.begin(), prime.end(), 0);
	for (ll i = 2; i * i <= MAX; ++i)
	{
		if (prime[i] == i)
		{
			for (ll j = i * i; j <= MAX; j += i)
			{
				if (prime[j] == j)
				{
					prime[j] = i;
				}
			}
		}
	}
	int T = 0, cnt = 1;
	cin >> T;
	while (T--)
	{
		map<int, int>mm;
		ll b = 1;
		int n = 0, m = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			int x = 0;
			cin >> x;
			while (x != 1)
			{
				mm[prime[x]]++;
				x /= prime[x];
			}
		}
		for (int i = 0; i < m; ++i)
		{
			int x = 0;
			cin >> x;
			while (x != 1)
			{
				int pivot = prime[x];
				if (mm.find(pivot) == mm.end())
				{
					b *= pivot;
				}
				else
				{
					if (--mm[pivot] == 0)
					{
						mm.erase(pivot);
					}
				}
				x /= pivot;
			}
		}
		ll ans = 1;
		for (auto& [a, b] : mm)
		{
			for (int j = 0; j < b; ++j)
			{
				ans *= a;
			}
		}
		cout << format("Case #{}: {} / {}\n", cnt++, ans, b);
	}
	return 0;
}