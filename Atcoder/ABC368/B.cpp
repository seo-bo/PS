#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	priority_queue<int>pq;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		pq.push(temp);
	}
	int ans = 0;
	while (pq.size() > 1)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		if (a > 1)
		{
			pq.push(a - 1);
		}
		if (b > 1)
		{
			pq.push(b - 1);
		}
		ans++;
	}
	cout << ans;
	return 0;
}
