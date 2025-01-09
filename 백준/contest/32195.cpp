#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n;
	vector<ll>in, out;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		ll pivot = a * a + b * b;
		if (b >= a && b >= -a)
		{
			in.push_back(pivot);
		}
		else
		{
			out.push_back(pivot);
		}
	}
	sort(in.begin(), in.end());
	cin >> q;
	while (q--)
	{
		ll p = 0;
		cin >> p;
		ll pivot = p * p;
		vector<ll>ans(3);
		ans[0] = out.size();
		ans[1] = upper_bound(in.begin(), in.end(), pivot) - in.begin();
		ans[2] = in.size() - ans[1];
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
