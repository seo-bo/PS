#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end(), [&](const string& a, const string& b)
		{
			if (a.length() != b.length())
			{
				return a.length() < b.length();
			}

			int s1 = 0, s2 = 0;
			for (auto& i : a)
			{
				if (isdigit(i))
				{
					s1 += i - '0';
				}
			}
			for (auto& i : b)
			{
				if (isdigit(i))
				{
					s2 += i - '0';
				}
			}
			if (s1 != s2)
			{
				return s1 < s2;
			}
			return a < b;
		});
	for (auto& i : v)
	{
		cout << i << '\n';
	}
	return 0;
}