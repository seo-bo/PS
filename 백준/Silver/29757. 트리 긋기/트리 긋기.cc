#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector < tuple<int, int, int>>v;
	for (int i = 0; i < n; ++i)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		v.push_back(make_tuple(x, y, i + 1));
	}
	sort(v.begin(), v.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b)
		{
			if (get<0>(a) == get<0>(b))
			{
				return get<1>(a) > get<1>(b);
			}
			return get<0>(a) < get<0>(b);
		});
	for (int i = 0; i < n - 1; ++i)
	{
		cout << get<2>(v[i]) << " " << get<2>(v[i + 1]) << "\n";
	}
	return 0;
}