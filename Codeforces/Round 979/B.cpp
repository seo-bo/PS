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
		if (n == 1)
		{
			cout << 0 << '\n';
			continue;
		}
		for (int i = 0; i < n - 1; ++i)
		{
			cout << 0;
		}
		cout << 1 << '\n';
	}
	return 0;
}
