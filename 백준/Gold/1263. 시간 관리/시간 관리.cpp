#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (auto& [a, b] : v)
	{
		cin >> b >> a;
	}
	sort(v.rbegin(), v.rend());
	int ans = INT_MAX;
	for (auto& [a, b] : v)
	{
		ans = min(ans, a) - b;
	}
	cout << max(-1, ans);
	return 0;
}