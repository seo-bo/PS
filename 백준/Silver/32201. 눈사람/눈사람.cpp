#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, t = 0;
	cin >> n;
	map<int, int>mm;
	vector<ti>v;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		mm[t] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		v.push_back(make_tuple(mm[t] - i, i, t));
	}
	sort(v.begin(), v.end(), [&](ti& a, ti& b)
		{
			if (get<0>(a) == get<0>(b))
			{
				return get<1>(a) < get<1>(b);
			}
			return get<0>(a) > get<0>(b);
		});
	int pre = get<0>(v[0]);
	for (auto& [a, b, c] : v)
	{
		if (pre != a)
		{
			break;
		}
		cout << c << ' ';
	}
	return 0;
}