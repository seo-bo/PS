#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
		vector<int>a(n);
		vector<int>b(m);
		for (auto& i : a)
		{
			cin >> i;
		}
		for (auto& i : b)
		{
			cin >> i;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll ans = 0;
		for (auto& i : b)
		{
			ans += a.end() - upper_bound(a.begin(), a.end(), i);
		}
		cout << ans << '\n';
	}
	return 0;
}