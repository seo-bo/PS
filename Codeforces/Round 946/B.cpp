#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		string str;
		cin >> str;
		string r = "";
		for (auto& i : str)
		{
			if (r.find(i) == string::npos)
			{
				r += i;
			}
		}
		sort(r.begin(), r.end());
		string s = "";
		for (auto& i : str)
		{
			int idx = r.find(i);
			int S = r.length() - 1 - idx;
			s += r[S];
		}
		cout << s << "\n";
	}
	return 0;
}

