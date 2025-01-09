#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		map<pair<ll, ll>, ll> pt1, pt2, pt3;
		map<tuple<ll, ll, ll>, ll> tpt1, tpt2, tpt3;
		ll result = 0;
		for (int i = 0; i < n - 2; ++i)
		{
			pair<ll, ll>f = make_pair(v[i], v[i + 1]);
			pair<ll, ll>s = make_pair(v[i + 1], v[i + 2]);
			pair<ll, ll>t = make_pair(v[i], v[i + 2]);
			tuple<ll, ll, ll> a = make_tuple(v[i], v[i + 1], v[i + 2]);
			pt1[f]++;
			pt2[s]++;
			pt3[t]++;
			tpt1[a]++;
			tpt2[a]++;
			tpt3[a]++;
			result += pt1[f] - tpt1[a];
			result += pt2[s] - tpt2[a];
			result += pt3[t] - tpt3[a];
		}
		cout << result << "\n";
	}
	return 0;
}
