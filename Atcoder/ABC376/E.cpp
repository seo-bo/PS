#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, k = 0;
		cin >> n >> k;
		vector<pll>v(n);
		for (auto& [a, _] : v)
		{
			cin >> a;
		}
		for (auto& [_, b] : v)
		{
			cin >> b;
		}
		sort(v.begin(), v.end());
		priority_queue<ll>pq;
		ll sum = 0, ans = LLONG_MAX;
		for (auto& [a, b] : v)
		{
			sum += b;
			pq.push(b);
			if (pq.size() > k)
			{
				sum -= pq.top();
				pq.pop();
			}
			if (pq.size() == k)
			{
				ans = min(ans, a * sum);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
