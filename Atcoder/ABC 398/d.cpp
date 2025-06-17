#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void) // 그냥 가준만큼 빼도...
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	map<char, pii>mm = { {'N',{-1,0}},{'S',{1,0}},{'W',{0,-1}},{'E',{0,1}} };
	string str, ans;
	cin >> str;
	set<pii>s;
	s.insert(make_pair(0, 0));
	int a = 0, b = 0;
	for (auto& i : str)
	{
		auto [pa, pb] = mm[i];
		a += pa, b += pb;
		s.insert(make_pair(a, b));
		if (s.find(make_pair(a - x, b - y)) == s.end())
		{
			ans += '0';
			continue;
		}
		ans += '1';
	}
	cout << ans;
	return 0;
}
