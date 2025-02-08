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
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>v(n), pivot;
	vector<pii>temp;
	ll ans = 0;
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 1; i < n; ++i)
	{
		temp.push_back(make_pair(v[i] - v[i - 1], i - 1));
	}
	sort(temp.begin(), temp.end(), greater<pii>());
	for (int i = 0; i < k - 1; ++i)
	{
		pivot.push_back(temp[i].second);
	}
	int idx = 0;
	sort(pivot.begin(), pivot.end());
	for (auto& i : pivot)
	{
		ans += (ll)v[i] - (ll)v[idx];
		idx = i + 1;
	}
	cout << ans + (ll)v[n - 1] - (ll)v[idx];
	return 0;
}