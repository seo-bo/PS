#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll ans = 0;
		int n = 0;
		cin >> n;
		vector<vector<int>>v(20001);
		vector<pii>temp(n);
		for (auto& [i, j] : temp)
		{
			cin >> i >> j;
			i += 10000;
			j += 10000;
		}
		auto check = [&](int a)
			{
				if (a < 0 || a > 20000)
				{
					return false;
				}
				return true;
			};
		sort(temp.begin(), temp.end(), [&](const pii& a, const pii& b)
			{
				if (a.first == b.first)
				{
					return a.second < b.second;
				}
				return a.first < b.first;
			});
		for (auto& [a, b] : temp)
		{
			v[a].push_back(b);
		}
		for (int i = 0; i < n; ++i)
		{
			auto& [x1, y1] = temp[i];
			for (int j = i + 1; j < n; ++j)
			{
				auto& [x2, y2] = temp[j];
				int a = x1 - x2, b = y1 - y2;
				ll pivot = (1LL * a * a) + (1LL * b * b);
				if (pivot <= ans)
				{
					continue;
				}
				int a1 = x1 + b, b1 = y1 - a, a2 = x2 + b, b2 = y2 - a;
				pii p1 = make_pair(a1, b1), p2 = make_pair(a2, b2);
				if (p1 == temp[i] || p1 == temp[j] || p2 == temp[i] || p2 == temp[j] || p1 == p2)
				{
					continue;
				}
				if (check(a1) && check(b1) && check(a2) && check(b2))
				{
					if (binary_search(v[a1].begin(), v[a1].end(), b1) && binary_search(v[a2].begin(), v[a2].end(), b2))
					{
						ans = max(ans, pivot);
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}