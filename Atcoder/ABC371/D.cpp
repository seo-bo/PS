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
	cin >> n;
	vector<ll>x(n, 0), p(n, 0), prefix(n + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		prefix[i] = prefix[i - 1] + p[i - 1];
	}
	cin >> q;
	while (q--)
	{
		int left = 0, right = 0;
		cin >> left >> right;
		int l = lower_bound(x.begin(), x.end(), left) - x.begin();
		int r = upper_bound(x.begin(), x.end(), right) - x.begin() - 1;
		if (l <= r && l < n && r >= 0)
		{
			cout << prefix[r + 1] - prefix[l] << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	return 0;
}
