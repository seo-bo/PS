#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<int>v(8);
	vector<vector<int>>ans(3);
	for (int i = 0; i < 8; ++i)
	{
		cin >> v[i];
	}
	map<int, int>s;
	for (int i = 0; i < 7; ++i)
	{
		int temp = 0;
		cin >> temp;
		s[temp]++;
	}
	auto cal = [&](int siz, int cnt)
		{
			int idx = 0;
			for (int i = 0; i < siz; i += 2)
			{
				int pivot = -1;
				if (s.find(v[i]) != s.end())
				{
					pivot = v[i];
					if (!(--s[v[i]]))
					{
						s.erase(v[i]);
					}
				}
				else if (s.find(v[i + 1]) != s.end())
				{
					pivot = v[i + 1];
					if (!(--s[v[i + 1]]))
					{
						s.erase(v[i + 1]);
					}
				}
				v[idx++] = pivot;
				ans[cnt].push_back(pivot);
			}
		};
	cal(8, 2);
	cal(4, 1);
	if (s.find(v[0]) != s.end())
	{
		ans[0].push_back(v[0]);
	}
	else if (s.find(v[1]) != s.end())
	{
		ans[0].push_back(v[1]);
	}
	for (auto& i : ans)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}