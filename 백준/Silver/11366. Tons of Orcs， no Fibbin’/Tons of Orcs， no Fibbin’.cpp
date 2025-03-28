#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii>v(101);
	v[1] = make_pair(1, 1);
	v[2] = make_pair(1, 2);
	for (int i = 3; i <= 100; ++i)
	{
		v[i] = make_pair(v[i - 1].first + v[i - 2].first, v[i - 1].second + v[i - 2].second);
	}
	while (1)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (!a && !b && !c)
		{
			break;
		}
		if (a == 0 && b == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		auto& [x, y] = v[c];
		cout << x * a + y * b << '\n';
	}
	return 0;
}