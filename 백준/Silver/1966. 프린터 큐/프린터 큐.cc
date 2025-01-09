#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		deque<pii>dq;
		priority_queue<int>pq;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			dq.push_back(make_pair(temp, i));
			pq.push(temp);
		}
		int ans = 1;
		while (!dq.empty())
		{
			int target = pq.top();
			while (dq.front().first != target)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			if (dq.front().second == m)
			{
				break;
			}
			ans++;
			pq.pop();
			dq.pop_front();
		}
		cout << ans << '\n';
	}
	return 0;
}