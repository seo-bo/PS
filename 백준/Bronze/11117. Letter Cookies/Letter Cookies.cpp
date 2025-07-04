#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		map<char, int>mm;
		for (auto& i : str)
		{
			mm[i]++;
		}
		int q = 0;
		cin >> q;
		while (q--)
		{
			auto sv = [&]
				{
					string a;
					cin >> a;
					map<char, int>temp = mm;
					for (auto& i : a)
					{
						if (--temp[i] == -1)
						{
							return false;
						}
					}
					return true;
				};
			cout << (sv() ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}