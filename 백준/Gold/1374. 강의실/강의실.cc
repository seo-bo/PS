#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ti>v(n);
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
	}
	sort(v.begin(), v.end(), [&](const ti& a, const ti& b)
		{
			if (get<1>(a) == get<1>(b))
			{
				return get<2>(a) < get<2>(b);
			}
			return get<1>(a) < get<1>(b);
		});
	priority_queue<int, vector<int>, greater<>>pq;
	int ans = 0;
	for (auto& [a, b, c] : v)
	{
		if (pq.empty() || pq.top() > b)
		{
			pq.push(c);
		}
		else
		{
			while (!pq.empty() && pq.top() <= b)
			{
				pq.pop();
			}
			pq.push(c);
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
	return 0;
}