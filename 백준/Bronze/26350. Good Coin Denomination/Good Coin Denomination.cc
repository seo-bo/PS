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
		int n = 0, pre = -1;
		cin >> n;
		bool flag = true;
		vector<int>v(n);
		for (auto& i : v)
		{
			cin >> i;
			if (pre * 2 > i)
			{
				flag = false;
			}
			pre = i;
		}
		cout << "Denominations: ";
		for (auto& i : v)
		{
			cout << i << ' ';
		}
		cout << '\n';
		cout << (flag ? "Good " : "Bad ") << "coin denominations!" << '\n' << '\n';
	}
	return 0;
}