#include <bits/stdc++.h>
#include <unordered_set>
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
	ll n = 0;
	cin >> n;
	deque<ll>dq;
	dq.push_back(n);
	ll ans = 0;
	while (!dq.empty())
	{
		if (dq.front() == 1)
		{
			dq.pop_front();
			continue;
		}
		ll pivot = dq.front();
		dq.pop_front();
		ll p1 = (pivot + 1) / 2, p2 = pivot / 2;
		ans += p1 * p2;
		dq.push_back(p1), dq.push_back(p2);
	}
	cout << ans;
	return 0;
}