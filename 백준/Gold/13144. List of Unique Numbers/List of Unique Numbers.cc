#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	set<int>s;
	ll ans = 0, left = 0;
	for (int right = 0; right < n; ++right)
	{
		while (s.find(v[right]) != s.end())
		{
			s.erase(v[left++]);
		}
		s.insert(v[right]);
		ans += right - left + 1LL;
	}
	cout << ans;
	return 0;
}