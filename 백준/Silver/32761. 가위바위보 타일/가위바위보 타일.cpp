#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<int>v(1, 0);
	unordered_map<char, int>mm = { {'S',0},{'P',1},{'R',2} };
	vector<vector<int>>temp = { {0,1,2},{1,2,0},{2,0,1} };
	for (auto& i : str)
	{
		v.push_back(mm[i]);
	}
	ll ans = 0;
	auto cal = [&](int num)
		{
			int idx = 0;
			deque<int>tt;
			for (int i = 1; i <= n; ++i)
			{
				if (v[i] == temp[num][idx])
				{
					tt.push_back(v[i]);
					idx = (idx + 1) % 3;
				}
			}
			while (!tt.empty() && (tt.back() + 1) % 3 != tt.front())
			{
				tt.pop_back();
			}
			ans = max(ans, (ll)tt.size());
		};
	for (int i = 0; i < 3; ++i)
	{
		cal(i);
	}
	cout << n - ans;
	return 0;
}