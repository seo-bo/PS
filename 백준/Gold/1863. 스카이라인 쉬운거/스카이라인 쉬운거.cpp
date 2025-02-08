#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>ti;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>s;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		while (!s.empty() && s.back() > b)
		{
			ans++;
			s.pop_back();
		}
		if (s.empty() || s.back() != b)
		{
			s.push_back(b);
		}
	}
	while (!s.empty() && s.back() > 0)
	{
		ans++;
		s.pop_back();
	}
	cout << ans;
	return 0;
}