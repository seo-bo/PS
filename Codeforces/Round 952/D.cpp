#include <bits/stdc++.h>
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
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		vector<pii>v;
		for (int i = 0; i < a; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < b; ++j)
			{
				if (str[j] == '#')
				{
					v.push_back(make_pair(i + 1, j + 1));
				}
			}
		}
		ll sx = 0, sy = 0;
		for (auto& i : v)
		{
			sx += i.first, sy += i.second;
		}
		int siz = v.size();
		cout << sx / siz << ' ' << sy / siz << '\n';
	}
	return 0;
}
