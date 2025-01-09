#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	while (cin >> s >> t)
	{
		int slen = s.length(), tlen = t.length(), idx = 0;
		for (int i = 0; i < tlen && idx < slen; ++i)
		{
			while (s[idx] != t[i] && i < tlen)
			{
				i++;
			}
			if (i < tlen && idx < slen && s[idx] == t[i])
			{
				idx++;
			}
		}
		if (idx == slen)
		{
			cout << "Yes" << '\n';
		}
		else
		{
			cout << "No" << '\n';
		}
	}
	return 0;
}