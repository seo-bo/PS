#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<int>v;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (b <= a)
		{
			ans++;
			continue;
		}
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int idx = 0, len = v.size(), temp = 0;
	while (idx < len) // 작은 값을 주는게 손해라면, 공매도?
	{
		idx++; // 수강신청을 못하는게 목적이라면, 이미 달구가 고른놈은 무시하는게 맞긴함. 최대한 애매하게 남기는 전략이란?
		ans++;
		int now = m - 1 + temp;
		while (idx < len && now >= v[idx])
		{
			now -= min(v[idx++], now);
		}
		temp = now;
	}
	cout << ans;
	return 0;
}