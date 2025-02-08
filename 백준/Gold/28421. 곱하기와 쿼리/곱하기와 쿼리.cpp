#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	bool zero = false;
	map<int, int>mm;
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		if (!v[i])
		{
			zero = true;
			continue;
		}
		mm[v[i]]++;
	}
	auto check = [&](int pivot)
		{
			for (int i = 1; i * i <= pivot; ++i)
			{
				if (pivot % i)
				{
					continue;
				}
				int a = i;
				if (a == pivot / a)
				{
					if (mm[a] >= 2)
					{
						return true;
					}
					continue;
				}
				int b = pivot / i;
				if (mm.find(a) != mm.end() && mm.find(b) != mm.end())
				{
					return true;
				}
			}
			return false;
		};
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			if (b == 0)
			{
				cout << ((zero && n > 1) ? 1 : 0) << '\n';
			}
			else
			{
				cout << (check(b) ? 1 : 0) << '\n';
			}
		}
		else
		{
			if (!v[b])
			{
				continue;
			}
			if (--mm[v[b]] == 0)
			{
				mm.erase(v[b]);
			}
			v[b] = 0;
			zero = true;
		}
	}
	return 0;
}