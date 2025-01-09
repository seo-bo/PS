#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)// 외판원 순회랑 비슷하네
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	lb s = 0, t = 0;
	cin >> n >> s >> t;
	vector<pair<plb, plb>>v(n);
	for (auto& [a, b] : v)
	{
		cin >> a.first >> a.second >> b.first >> b.second;
	}
	vector<int>per(n);
	iota(per.begin(), per.end(), 0);
	lb ans = 1e18;
	auto dis = [&](plb a, plb b)
		{
			return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
		};
	do
	{
		for (int i = 0; i < (1 << n); ++i)
		{
			lb time = 0;
			plb cur = make_pair(0, 0);
			bool check = true;
			for (int j = 0; j < n; ++j)
			{
				int idx = per[j];
				plb st = v[idx].first;
				plb ed = v[idx].second;
				if (i & (1 << j))
				{
					swap(st, ed);
				}
				lb a = dis(cur, st);
				lb b = dis(st, ed);
				time += (a / s) + (b / t);
				cur = ed;
			}
			ans = min(ans, time);
		}
	} while (next_permutation(per.begin(), per.end()));
	cout << fixed << setprecision(14) << ans;
	return 0;
}
