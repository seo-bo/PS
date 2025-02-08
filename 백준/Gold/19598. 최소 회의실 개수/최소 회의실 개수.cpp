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
	vector<pii>v(n);
	for (auto& [i, j] : v)
	{
		cin >> i >> j;
	}
	sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first < b.first;
		});
	priority_queue<int, vector<int>, greater<>>pq;
	int ans = 0;
	for (auto& [i,j] : v)
	{
		if (pq.empty())
		{
			pq.push(j);
		}
		else
		{
			while (!pq.empty() && pq.top() <= i)
			{
				pq.pop();
			}
			pq.push(j);
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
	return 0;
}