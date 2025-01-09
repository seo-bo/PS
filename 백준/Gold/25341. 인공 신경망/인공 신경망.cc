#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl;
typedef tuple<ll, ll, ll, ll> tll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, q = 0, a = 0, t = 0;
	cin >> n >> m >> q;
	ll tt = 0;
	vector<vector<pii>>v(m + 1);
	vector<ll>neuron(n + 1, 0);
	vector<int>weight(m + 2, 0), fin(m + 2, 0);
	weight[m + 1] = 1;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a;
		vector<int>temp(a);
		for (auto& k : temp)
		{
			cin >> k;
		}
		for (int j = 0; j < a; ++j)
		{
			cin >> t;
			v[i].push_back(make_pair(temp[j], t));
		}
		cin >> weight[i];
	}
	for (int i = 1; i <= m + 1; ++i)
	{
		cin >> fin[i];
		tt += (ll)weight[i] * (ll)fin[i];
	}
	for (int _ = 1; _ <= m; ++_)
	{
		for (auto& [i, j] : v[_])
		{
			neuron[i] += (ll)j * (ll)fin[_];
		}
	}
	while (q--)
	{
		ll ans = tt, b = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> b;
			ans += b * neuron[i];
		}
		cout << ans << '\n';
	}
	return 0;
}