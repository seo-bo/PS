#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);;
	int n = 0;
	cin >> n;
	vector<int>v(n);
	vector<int>s;
	for (auto& i : v)
	{
		cin >> i;
	}
	for (auto& i : v)
	{
		if (s.empty())
		{
			s.push_back(i);
		}
		else
		{
			auto it = lower_bound(s.begin(), s.end(), i);
			if (it == s.end())
			{
				s.push_back(i);
			}
			else if (*it > i)
			{
				*it = i;
			}
		}
	}
	cout << s.size();
	return 0;
}