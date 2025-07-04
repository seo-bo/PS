#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	set<int>s;
	vector<int>ans(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		s.insert(i);
	}
	while (q--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		auto st = s.lower_bound(a);
		for (auto i = st; i != s.end() && *i <= b;)
		{
			ans[*i] = c;
			auto temp = i;
			++i;
			s.erase(temp);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}