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
	int n = 0, k = 0;
	cin >> n >> k;
	if (k >= n)
	{
		cout << 0;
		return 0;
	}
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	vector<pii>temp;
	for (int i = 1; i < n; ++i)
	{
		temp.push_back(make_pair(v[i] - v[i - 1], i - 1));
	}
	sort(temp.begin(), temp.end(), greater<pii>());
	vector<int>ans;
	for (int i = 0; i < k - 1; ++i)
	{
		ans.push_back(temp[i].second);
	}
	sort(ans.begin(), ans.end());
	int idx = 0;
	ll res = 0;
	for (auto& i : ans)
	{
		res += (v[i] - v[idx]);
		idx = i + 1;
	}
	cout << res + (v[n - 1] - v[idx]);
	return 0;
}