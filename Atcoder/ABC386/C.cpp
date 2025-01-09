#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int k = 0;
	string s, t;
	cin >> k >> s >> t;
	if (s == t)
	{
		cout << "Yes";
		return 0;
	}
	int slen = s.size(), tlen = t.size();
	if (abs(slen - tlen) > 1)
	{
		cout << "No";
		return 0;
	}
	if (slen == tlen)
	{
		int diff = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != t[i])
			{
				diff++;
			}
			if (diff > 1)
			{
				cout << "No";
				return 0;
			}
		}
		cout << ((diff <= 1) ? "Yes" : "No");
	}
	else
	{
		if (slen > tlen)
		{
			swap(s, t);
		}
		int i = 0, j = 0, diff = 0;
		while (i < slen && j < tlen)
		{
			if (s[i] == t[j])
			{
				i++;
				j++;
			}
			else
			{
				diff++;
				j++;
				if (diff > 1)
				{
					cout << "No";
					return 0;
				}
			}
		}
		cout << "Yes";
	}
	return 0;
}
