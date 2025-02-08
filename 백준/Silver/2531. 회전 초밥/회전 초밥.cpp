#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, d = 0, k = 0, c = 0;
	cin >> n >> d >> k >> c;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int ans = 0;
	map<int, int>m;
	for (int i = 0; i < k; ++i)
	{
		m[v[i % n]]++;
	}
	ans = m.size();
	for (int i = 0; i < n; ++i)
	{
		m[v[i]] == 1 ? m.erase(v[i]) : m[v[i]]--;
		m[v[(i + k) % n]]++;
		ans = max((m.find(c) == m.end()) ? (int)m.size() + 1 : (int)m.size(), ans);
	}
	cout << ans;
	return 0;
}