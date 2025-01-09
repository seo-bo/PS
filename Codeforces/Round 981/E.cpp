#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		vector<bool>visited(n + 1, false);
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!visited[i])
			{
				ll pivot = 0, x = i;
				while (!visited[x])
				{
					visited[x] = true;
					pivot++;
					x = v[x];
				}
				if (pivot >= 3)
				{
					ans += (pivot - 1) / 2;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
