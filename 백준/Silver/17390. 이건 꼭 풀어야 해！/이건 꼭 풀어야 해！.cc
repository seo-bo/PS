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
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	vector<ll>prefix(n + 1, 0);
	for (int i = 1; i <= n; ++ i)
	{
		prefix[i] = prefix[i - 1] + (ll)v[i - 1];
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << prefix[b] - prefix[a - 1] << '\n';
	}
	return 0;
}