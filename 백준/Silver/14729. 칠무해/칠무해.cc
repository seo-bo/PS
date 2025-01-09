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
	cin >> n;
	priority_queue<double>pq;
	for (int i = 0; i < n; ++i)
	{
		double temp = 0;
		cin >> temp;
		if (pq.size() >= 7 && pq.top() > temp)
		{
			pq.pop();
			pq.push(temp);
		}
		else if (pq.size() < 7)
		{
			pq.push(temp);
		}
	}
	deque<double>ans;
	for (int i = 0; i < 7; ++i)
	{
		ans.push_front(pq.top());
		pq.pop();
	}
	while (!ans.empty())
	{
		cout << fixed << setprecision(3) << ans.front() << '\n';
		ans.pop_front();
	}
	return 0;
}