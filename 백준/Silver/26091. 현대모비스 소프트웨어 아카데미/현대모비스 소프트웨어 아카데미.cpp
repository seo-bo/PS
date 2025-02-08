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
	deque<ll>dq;
	ll n = 0, m = 0, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		dq.push_back(temp);
	}
	sort(dq.begin(), dq.end(), greater<ll>());
	while (dq.size() > 1)
	{
		ll a = dq.front();
		dq.pop_front();
		while (!dq.empty() && a + dq.back() < m)
		{
			dq.pop_back();
		}
		if (dq.empty())
		{
			break;
		}
		dq.pop_back();
		ans++;
	}
	cout << ans;
	return 0;
}