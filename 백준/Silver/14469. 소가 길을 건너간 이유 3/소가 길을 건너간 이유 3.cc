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
	int n = 0;
	ll time = 0;
	cin >> n;
	deque<pll>dq;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		dq.push_back(make_pair(a, b));
	}
	sort(dq.begin(), dq.end());
	for (auto& i : dq)
	{
		auto [a, b] = i;
		if (time < a)
		{
			time = a;
		}
		time += b;
	}
	cout << time;
	return 0;
}