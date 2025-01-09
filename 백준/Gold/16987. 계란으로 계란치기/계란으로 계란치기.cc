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
	int n = 0;
	cin >> n;
	vector<pii>v;
	int ans = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	function<void(int, int, int)> dfs = [&](int sum, int cnt, int idx)
		{
			if (idx == n || cnt <= 1)
			{
				ans = max(ans, sum);
				return;
			}
			if (v[idx].first <= 0)
			{
				dfs(sum, cnt, idx + 1);
				return;
			}
			for (int i = 0; i < n; ++i)
			{
				auto [s1, w1] = v[i];
				if (idx == i || s1 <= 0)
				{
					continue;
				}
				auto [s2, w2] = v[idx];
				v[i] = make_pair(s1 - w2, w1);
				v[idx] = make_pair(s2 - w1, w2);
				int pivot = (v[i].first <= 0) + (v[idx].first <= 0);
				dfs(sum + pivot, cnt - pivot, idx + 1);
				v[idx] = make_pair(s2, w2);
				v[i] = make_pair(s1, w1);
			}
		};
	dfs(0, n, 0);
	cout << ans;
	return 0;
}