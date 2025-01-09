#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	while (cin >> n)
	{
		vector<int>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		vector<int>s;
		for (auto& i : v)
		{
			if (s.empty())
			{
				s.push_back(i);
				continue;
			}
			auto it = lower_bound(s.begin(), s.end(), i);
			if (it == s.end())
			{
				s.push_back(i);
			}
			else
			{
				*it = i;
			}
		}
		cout << s.size() << '\n';
	}
	return 0;
}