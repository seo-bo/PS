#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	ll ans = (1LL << n) - 1;
	int pivot = max((n - a) + (n - b) - n, a + b - n);
	for (int i = 0; i < pivot; ++i)
	{
		ans &= ~(1LL << i);
	}
	cout << ans;
	return 0;
}