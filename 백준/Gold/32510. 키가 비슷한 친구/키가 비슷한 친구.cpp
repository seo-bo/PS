#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	for (int _ = 1; _ <= T; ++_)
	{
		ll cost = 0;
		int n = 0, k = 0;
		cin >> n >> k;
		vector<pii>v(n);
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			v[i] = make_pair(i, temp);
		}
		sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
			{
				if (a.second == b.second)
				{
					return a.first < b.first;
				}
				return a.second < b.second;
			});
		priority_queue<pii, vector<pii>, greater<pii>>pq;
		for (auto& [a, b] : v) 
		{
			int pivot = b - k;
			while (!pq.empty() && pq.top().second < pivot)
			{
				pq.pop();
			}
			if (!pq.empty() && pq.top().first < a)
			{
				cost += 1LL * abs(pq.top().first - a);
			}
			pq.push(make_pair(a, b));
		}
		cout << "Case #" << _ << '\n';
		cout << cost << '\n';
	}
	return 0;
}