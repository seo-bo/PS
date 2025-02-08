#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, idx = 0;
	cin >> n >> m;
	vector<tuple<int, int, string>>v(n);
	for (auto& [a, b, c] : v)
	{
		cin >> c >> a;
		b = idx++;
	}
	sort(v.begin(), v.end(), [&](const tuple<int, int, string>& a, const tuple<int, int, string>& b)
		{
			if (get<0>(a) == get<0>(b))
			{
				return get<1>(a) < get<1>(b);
			}
			return get<0>(a) < get<0>(b);
		});
	while (m--)
	{
		int temp = 0;
		cin >> temp;
		auto it = lower_bound(v.begin(), v.end(), make_tuple(temp, 0, ""));
		cout << get<2>(*it) << '\n';
	}
	return 0;
}