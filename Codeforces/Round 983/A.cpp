#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n * 2);
		int  cnt = 0;
		for (auto& i : v)
		{
			cin >> i;
			cnt += i;
		}
		ll f = (cnt / 2), f1 = (2 * n - cnt) / 2;
		ll a = n - f - f1, b = min(cnt, 2 * n - cnt);
		cout << a << ' ' << b << '\n';
	}
	return 0;
}
