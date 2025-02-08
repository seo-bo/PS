#include <bits/stdc++.h>
#define P 1422
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		int n = 0;
		cin >> n;
		if (!n)
		{
			break;
		}
		vector<int>v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			v.push_back(2 * P - v[i]);
		}
		sort(v.begin(), v.end());
		int cur = 0;
		if (v[0] != 0)
		{
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		auto sv = [&]
			{
				while (cur + 200 < 2 * P)
				{
					int pivot = cur + 200;
					auto it = upper_bound(v.begin(), v.end(), pivot);
					if (it != v.begin())
					{
						it--;
					}
					if (*it <= cur)
					{
						cout << "IMPOSSIBLE" << '\n';
						return;
					}
					cur = *it;
				}
				cout << "POSSIBLE" << '\n';
			};
		sv();
	}
	return 0;
}
