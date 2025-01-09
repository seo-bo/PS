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
	int n = 0, d = 0, k = 0, c = 0, ans = 0;
	cin >> n >> d >> k >> c;
	vector<int>v(2 * n + 3, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for (int i = n; i < 2 * n; ++i)
	{
		v[i] = v[i - n];
	}
	unordered_map<int, int>ss;
	int left = 0, right = 0;
	for (; right < k; ++right)
	{
		ss[v[right]]++;
	}
	right--;
	ans = ss.size() + (ss.find(c) == ss.end());
	while (right < n + k)
	{
		if (!(--ss[v[left]]))
		{
			ss.erase(v[left]);
		}
		left++;
		ss[v[++right]]++;
		ans = max(ans, (int)ss.size() + (ss.find(c) == ss.end()));
	}
	cout << ans;
	return 0;
}