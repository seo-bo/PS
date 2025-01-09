#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pii>v;
	for (int i = 1; i < 200; ++i)
	{
		for (int j = i + 1; j < 200; ++j)
		{
			v.push_back(make_pair(i, j));
		}
	}
	sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
		{
			auto [A, B] = a;
			auto [C, D] = b;
			int amul = A * A + B * B;
			int bmul = C * C + D * D;
			if (amul == bmul)
			{
				return A < C;
			}
			return amul < bmul;
		});
	while (1)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (!a && !b)
		{
			return 0;
		}
		auto it = lower_bound(v.begin(), v.end(), make_pair(a, b), [&](const pii& l, const pii& r)
        {
            auto [A, B] = l;
            auto [C, D] = r;
            int amul = A * A + B * B;
            int bmul = C * C + D * D;
            if (amul == bmul)
            {
                return A < C || (A == C && B < D);
            }
            return amul < bmul;
        });
		if (it != v.end() && *it == make_pair(a, b))
		{
			it++;
		}
		cout << it->first << ' ' << it->second << '\n';
	}
	return 0;
}