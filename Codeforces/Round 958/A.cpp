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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0, ans = 0;
		cin >> a >> b;
		if (a == 1)
		{
			cout << 0 << '\n';
			continue;
		}
		priority_queue<int>pq;
		pq.push(a);
		while (!pq.empty())
		{
			int temp = pq.top();
			pq.pop();
			int tt = temp - b + 1;
			if (tt <= 1)
			{
				ans++;
				break;
			}
			else
			{
				pq.push(tt);
			}
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
