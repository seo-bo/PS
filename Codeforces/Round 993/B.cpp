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
		for (auto& i : str)
		{
			if (i == 'p')
			{
				i = 'q';
			}
			else if (i == 'q')
			{
				i = 'p';
			}
		}
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
	return 0;
}
