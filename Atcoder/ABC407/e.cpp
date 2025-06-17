#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>v(2 * n + 1);
		ll ans = 0;
		for (int i = 1; i <= 2 * n; ++i)
		{
			cin >> v[i];
		}
		priority_queue<ll>pq;
		int cnt = 0;
		for (int i = 1; i <= 2 * n; ++i)
		{
			pq.push(v[i]);
			while (!pq.empty() && cnt < (i + 1) / 2)
			{
				ans += pq.top();
				pq.pop();
				cnt++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
