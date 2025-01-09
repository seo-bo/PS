#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--) // 한 주기에서 다른 주기로 갈때 보이는거?
	{
		ll a = 0, b = 0, m = 0;
		cin >> a >> b >> m;
		cout << (m / a) + (m / b) + 2 << "\n";
	}
	return 0;
}
