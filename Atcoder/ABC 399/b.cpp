#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(make_pair(temp, i));
	}
	sort(v.rbegin(), v.rend());
	int cnt = 1, now = 1, pre = v[0].first;
	vector<int>ans(n + 1);
	for (auto& [a, b] : v)
	{
		if (pre != a)
		{
			now = cnt;
		}
		ans[b] = now;
		pre = a;
		cnt++;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
