#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int cur = 600;
	vector<pii>v;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int ah = a / 1000 * 600 + (a % 1000) / 100 * 60 + (a % 100);
		int bh = b / 1000 * 600 + (b % 1000) / 100 * 60 + (b % 100);
		v.push_back(make_pair(ah, bh));
	}
	v.push_back(make_pair(1330, 1330));
	sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first < b.first;
		});
	int ans = 0;
	for (auto& [a, b] : v)
	{
		if (cur + 10 < a)
		{
			ans = max(ans, a - (cur + 10));
		}
		cur = max(cur, b + 10);
	}
	cout << ans;
	return 0;
}