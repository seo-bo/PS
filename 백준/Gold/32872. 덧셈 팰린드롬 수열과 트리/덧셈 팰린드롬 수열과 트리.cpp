#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(1, 0);
	for (int i = 0; i < (1 << n) - 1; ++i)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	int st = (1 << (n - 1)), ed = (1 << (n)) - 1;
	auto sv = [&](int a, int b)
		{
			while (a != b)
			{
				a /= 2;
				b /= 2;
			}
			return a;
		};
	auto cal = [&](int a, int b)
		{
			int pivot = sv(a, b);
			vector<int>prefix(1, 0);
			vector<int>B;
			while (a != pivot)
			{
				prefix.push_back(prefix.back() + v[a]);
				a /= 2;
			}
			prefix.push_back(prefix.back() + v[pivot]);
			while (b != pivot)
			{
				B.push_back(v[b]);
				b /= 2;
			}
			int len = B.size() - 1;
			for (int i = len; i >= 0; --i)
			{
				prefix.push_back(prefix.back() + B[i]);
			}
			int m = prefix.size() - 1;
			for (int i = 1; i <= m - 1; ++i)
			{
				for (int j = i; j <= m - 1; ++j)
				{
					if (prefix[i] == (prefix[m] - prefix[j]))
					{
						return true;
					}
				}
			}
			return false;
		};
	int ans = 0;
	for (int i = st; i <= ed; ++i)
	{
		for (int j = i + 1; j <= ed; ++j)
		{
			if (cal(i, j))
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}