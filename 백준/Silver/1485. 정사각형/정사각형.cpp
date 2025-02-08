#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		vector<pll>v(4);
		auto d = [&](pll A, pll B)->ll
			{
				auto [a, b] = A;
				auto [c, d] = B;
				return (a - c) * (a - c) + (b - d) * (b - d);
			};
		auto c = [&]
			{
				vector<ll>t;
				for (int i = 0; i < 4; ++i)
				{
					for (int j = i + 1; j < 4; ++j)
					{
						t.push_back(d(v[i], v[j]));
					}
				}
				sort(t.begin(), t.end());
				return t[0] > 0 && t[0] == t[1] && t[1] == t[2] && t[2] == t[3] && t[4] == t[5];
			};
		for (auto& i : v)
		{
			cin >> i.first >> i.second;
		}
		cout << (c() ? 1 : 0) << '\n';
	}
	return 0;
}