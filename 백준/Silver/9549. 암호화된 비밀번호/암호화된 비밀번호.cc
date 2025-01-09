#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string a, b;
		cin >> a >> b;
		if (a.size() < b.size())
		{
			cout << "NO" << '\n';
			continue;
		}
		vector<int>aa(26, 0), bb(26, 0);
		ll pivot = 0;
		for (auto& i : b)
		{
			bb[i - 'a']++;
		}
		for (int i = 0; i < b.size(); ++i)
		{
			aa[a[i] - 'a']++;
		}
		if (aa == bb)
		{
			cout << "YES" << '\n';
			continue;
		}
		bool flag = false;
		int left = 0;
		for (int i = b.size(); i < a.size(); ++i)
		{
			aa[a[left++] - 'a']--;
			aa[a[i] - 'a']++;
			if (aa == bb)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}