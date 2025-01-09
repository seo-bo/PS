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
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>v;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	int ans = 0;
	for (auto& i : v)
	{
		ll time = pq.empty() ? 0 : pq.top();
		if (pq.size() == k)
		{
			pq.pop();
			time += i;
			pq.push(time);
		}
		else
		{
			time = i;
			pq.push(time);
		}
		if (time > m)
		{
			break;
		}
		ans++;
	}
	cout << ans;
	return 0;
}