#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 통 벌 벌 / 벌 벌 통 / 벌 통 벌
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1, 0), prefix(n + 1, 0);
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	for (int i = 2; i <= n; ++i)
	{
		ans = max(ans, prefix[i] - prefix[1] + prefix[n - 1] - prefix[i - 1]); // 벌 통 벌
		ans = max(ans, prefix[n] - v[1] - v[i] + prefix[n] - prefix[i]); // 벌 벌 통
		ans = max(ans, prefix[n] - v[n] - v[n - i + 1] + prefix[n - i]); // 통 벌 벌
	}
	cout << ans;
	return 0;
}