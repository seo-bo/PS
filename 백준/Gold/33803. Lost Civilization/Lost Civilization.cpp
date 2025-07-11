#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[i] = make_pair(temp, i + 1);
	}
	sort(v.begin(), v.end());
	if (v[0].first != 0 || v[1].first != 0)
	{
		cout << -1;
		return 0;
	}
	int now = 1, down = v[0].second, up = v[1].second, t = 0;
	set<pii>ans;
	for (int i = 2; i < n; ++i)
	{
		auto [a, b] = v[i];
		if (a > now)
		{
			cout << -1;
			return 0;
		}
		if (t == 0)
		{
			ans.insert(make_pair(down, b));
			down = b;
		}
		else
		{
			ans.insert(make_pair(up, b));
			up = b;
			now++;
		}
		t = (t + 1) % 2;
	}
	if (down != v.back().second)
	{
		ans.insert(make_pair(down, v.back().second));
	}
	if (up != v.back().second)
	{
		ans.insert(make_pair(up, v.back().second));
	}
	for (auto& [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	return 0;
}