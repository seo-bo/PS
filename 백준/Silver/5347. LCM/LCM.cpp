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
	int T = 1;
	cin >> T;
	while (T--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}
	return 0;
}