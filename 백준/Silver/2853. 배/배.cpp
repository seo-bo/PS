#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>div;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (temp == 1)
		{
			continue;
		}
		bool check = true;
		ll p = temp - 1;
		for (auto& j : div)
		{
			if (!(p % j))
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			div.push_back(p);
		}
	}
	cout << div.size();
	return 0;
}