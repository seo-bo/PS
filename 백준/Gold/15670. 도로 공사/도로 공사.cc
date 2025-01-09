#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>prefix(n + 2, 0), suffix(n + 2, 0), v(n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + (v[i - 1] >= v[i] || i == 1);
		suffix[i] = suffix[i - 1] + (v[i] >= v[i - 1] || i == 1);
	}
	while (m--) // 흠 그냥 하면 안될거같은데..
	{
		// 경계부분 조건을 체크 해주면 되나?
		int l = 0, r = 0, ans = 0;
		cin >> l >> r;
		ans = prefix[l - 1] + suffix[r] - suffix[l - 1] + prefix[n] - prefix[r];
		if (l > 1 && v[l - 1] > v[l]) // 기존 비교
		{
			ans++;
		}
		if (r < n && v[r] < v[r + 1])
		{
			ans++;
		}
		if (l > 1 && v[l - 1] < v[r]) // reverse 비교
		{
			ans--;
		}
		if (r < n && v[l] < v[r + 1])
		{
			ans--;
		}
		cout << ans << '\n';
	}
	return 0;
}