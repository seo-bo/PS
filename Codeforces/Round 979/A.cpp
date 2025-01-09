#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>tl;
typedef tuple<int, int, int>tp;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		if (n == 1)
		{
			cout << 0 << '\n';
			continue;
		}
		ll p1 = *max_element(v.begin(), v.end());
		ll p2 = *min_element(v.begin(), v.end());
		cout << (n - 1) * (p1 - p2) << '\n';
	}
	return 0;
}
