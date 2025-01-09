#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, d = 0, result = 0, cur = 0;
	cin >> n >> d;
	vector<pair<ll, ll>>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
	for (auto& i : v)
	{
		cur += i.second;
		pq.push(i);
		while (!pq.empty() && (i.first - pq.top().first >= d))
		{
			cur -= pq.top().second;
			pq.pop();
		}
		result = max(result, cur);
	}
	cout << result;
	return 0;
}