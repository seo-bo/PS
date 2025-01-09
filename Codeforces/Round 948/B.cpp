#include <bits/stdc++.h>
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
		int x = 0;
		cin >> x;
		vector<int>a;
		for (int i = 0; x > 0; ++i)
		{
			if (x & 1)
			{
				a.push_back(1);
				x >>= 1;
				if (x & 1)
				{
					a.back() = -1;
					x++;
				}
			}
			else
			{
				a.push_back(0);
				x >>= 1;
			}
		}
		cout << a.size() << "\n";
		for (int i = 0; i < a.size(); ++i)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
