#include <bits/stdc++.h>
using namespace std;
typedef long double lb;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int>pq;
	int n = 0, h = 0, t = 0;
	cin >> n >> h >> t;
	for (int i = 0; i < n; ++i)
	{
		int num = 0;
		cin >> num;
		pq.push(num);
	}
	int cnt = 0;
	while (pq.top() >= h && t > 0)
	{
		int cur = pq.top();
		pq.pop();
		cur = (cur == 1) ? 1 : cur / 2;
		pq.push(cur);
		t--;
		cnt++;
	}
	if (pq.top() >= h)
	{
		cout << "NO" << "\n";
		cout << pq.top();
	}
	else
	{
		cout << "YES" << "\n";
		cout << cnt;
	}
	return 0;
}