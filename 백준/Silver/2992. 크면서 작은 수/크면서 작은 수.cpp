#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	string n;
	ll ans = INT_MAX;
	cin >> n;
	ll pivot = stoll(n);
	sort(n.begin(), n.end());
	do
	{
		ll a = stoll(n);
		if (a > pivot)
		{
			ans = min(ans, a);
		}
	} while (next_permutation(n.begin(), n.end()));
	cout << ((ans == INT_MAX) ? 0 : ans);
	return 0;

}