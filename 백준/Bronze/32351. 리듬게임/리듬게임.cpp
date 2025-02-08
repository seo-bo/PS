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
	int n = 0, k = 0;
	lb s = 0;
	cin >> n >> s >> k;
	vector<pair<int, lb>>v;
	for (int i = 0; i < k; ++i)
	{
		int a = 0;
		lb b = 0;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	lb ans = 0;
	int pivot = 1;
	for (int i = 0; i < k; ++i)
	{
		auto [a, b] = v[i];
		ans += (a - pivot) * (60.0 / s) * 4;
		pivot = a;
		s = b;
	}
	ans += (n - pivot + 1) * (60.0 / s) * 4;
	cout << fixed << setprecision(15) << ans;
	return 0;
}