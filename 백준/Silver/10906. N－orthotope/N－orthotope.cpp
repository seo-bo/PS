#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>s1(11), s2(11), e1(11), e2(11);
	for (int i = 0; i < n; ++i)
	{
		cin >> s1[i] >> e1[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> s2[i] >> e2[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = max(s1[i], s2[i]), b = min(e1[i], e2[i]);
		if (a > b)
		{
			cout << -1;
			return 0;
		}
		else if (a < b)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}