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
		int n = 0;
		cin >> n;
		vector<int>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		bool check = true;
		for (int i = 1; i < n; ++i)
		{
			int pivot = abs(v[i] - v[i - 1]);
			if (pivot != 5 && pivot != 7)
			{
				check = false;
				break;
			}
		}
		cout << ((check) ? "YES" : "NO") << '\n';
	}
	return 0;
}
