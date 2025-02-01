#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>v(n + 1), p(n + 1, 1);
	ll ans = 0;
	iota(v.begin(), v.end(), 0);
	while (q--)
	{
		int t = 0;
		cin >> t;
		if (t == 1)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			int temp = v[a];
			v[a] = b;
			if (p[temp] == 2)
			{
				ans--;
			}
			p[temp]--;
			if (p[b] == 1)
			{
				ans++;
			}
			p[b]++;
		}
		else
		{
			cout << ans << '\n';
		}
	}
	return 0;
}
