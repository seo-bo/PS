#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll h = 0, sum = 0, n = 0, q = 0, temp = 0;
	cin >> h >> n >> q;
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		sum += temp;
		pq.push(temp);
	}
	while (sum - pq.top() >= h)
	{
		sum -= pq.top();
		pq.pop();
	}
	cout << ((sum < h) ? -1 : (int)pq.size()) << '\n';
	while (q--)
	{
		cin >> temp;
		if (sum >= h)
		{
			if (pq.top() < temp)
			{
				pq.push(temp);
				sum += temp;
				while (sum - pq.top() >= h)
				{
					sum -= pq.top();
					pq.pop();
				}
			}
			cout << pq.size() << '\n';
		}
		else // 더 작을때
		{
			pq.push(temp);
			sum += temp;
			if (sum >= h)
			{
				while (sum - pq.top() >= h)
				{
					sum -= pq.top();
					pq.pop();
				}
				cout << pq.size() << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}