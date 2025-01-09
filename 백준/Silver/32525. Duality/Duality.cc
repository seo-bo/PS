#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>ti;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ti>v(n);
		for (int i = 1; i <= n; ++i)
		{
			auto& [a, b, c] = v[i - 1];
			a = i;
			cin >> b >> c;
		}
		sort(v.begin(), v.end(), [&](const ti& a, const ti& b)
			{
				if (get<2>(a) == get<2>(b))
				{
					return get<1>(a) > get<1>(b);
				}
				return get<2>(a) > get<2>(b);
			});
		int pivot = 1000000000;
		for (auto& [a, _, c] : v)
		{
			cout << a << ' ' << pivot-- << ' ' << c + 1 << '\n';
		}
	}
	return 0;
}