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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int time = 0;
		string b;
		auto c = [&](string& s) -> int
			{
				int time = 2;
				for (int i = 1; i < s.length(); ++i)
				{
					if (s[i] == s[i - 1])
					{
						time += 1;
					}
					else
					{
						time += 2;
					}
				}
				return time;
			};
		for (char j = 'a'; j <= 'z'; ++j) 
		{
			for (int i = 0; i <= s.length(); ++i)
			{
				string ns = s.substr(0, i) + j + s.substr(i);
				int nt = c(ns);
				if (nt > time) 
				{
					time = nt;
					b = ns;
				}
			}
		}
		cout << b << '\n';
	}
	return 0;
}
