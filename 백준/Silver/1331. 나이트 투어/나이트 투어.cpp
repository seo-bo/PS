#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<string>v;
	unordered_set<string>mm;
	vector<pii> dir = { {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1} };
	for (int i = 0; i < 36; ++i)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	auto check = [&](string s1, string s2)
		{
			int a = s1[0] - 'A', b = s1[1] - '1', c = s2[0] - 'A', d = s2[1] - '1';
			for (auto& [i, j] : dir)
			{
				int x = a + i;
				int y = b + j;
				if (x == c && y == d)
				{
					return true;
				}
			}
			return false;
		};
	mm.insert(v[0]);
	for (int i = 1; i < 36; ++i)
	{
		if (!check(v[i - 1], v[i]) || mm.find(v[i]) != mm.end())
		{
			cout << "Invalid";
			return 0;
		}
		mm.insert(v[i - 1]);
	}
	if (check(v[35], v[0]))
	{
		cout << "Valid";
	}
	else
	{
		cout << "Invalid";
	}
	return 0;
}