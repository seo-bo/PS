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

int main(void) // imos?랑 비슷?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, u = 0, d = 0;
	cin >> n >> u >> d;
	vector<ll>a(n + 2, 0), b(n + 2, 0), prefix(n + 2, 0), ans(n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}
	ll pivot = u + d;
	ll weight = 0;
	for (int i = 1; i <= n; ++i)
	{
		weight += prefix[i];
		ans[i] += ans[i - 1];
		if (b[i] > a[i]) // 당장은 a 고르는게 이득이지만 뒤로 가면 갈수록 b를 고르는게 이득인 상황이 온다.
		{
			ll k = (b[i] - a[i]) / pivot; // 차이를 극복하면 b 고르는게 이득
			ll p = (b[i] - a[i]) % pivot;
			k = min(i + k, n);
			prefix[k + 1] -= pivot;
			ans[k + 1] += p;
			ans[i] += a[i] + weight;
			weight += u;
		}
		else
		{
			ans[i] += b[i] + weight;
			weight -= d;
		}

	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}