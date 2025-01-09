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
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	deque<pair<int, int>>dq;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		dq.push_back(make_pair(temp, 1));
	}
	sort(dq.begin(), dq.end());
	lb ans = 0;
	auto check = [&]
		{
			int idx = (dq.size() + 1) / 2;
			auto [a, b] = dq[idx - 1];
			ans = max(ans, (lb)a / (lb)b);
		};
	check();
	while (dq.size() > 1)
	{
		pii t;
		for (int i = 0; i < 2; ++i)
		{
			auto [a, b] = dq.front();
			auto& [c, d] = t;
			c += a, d += b;
			dq.pop_front();
		}
		dq.push_front(t);
		check();
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}