#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false); // 하나에 15개?
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0, cnt =0;
		cin >> a >> b;
		vector<int>v(100, 15);
		for (auto& i : v)
		{
			if (b <= 0)
			{
				break;
			}
			i -= 4 * min(2, b);
			b -= 2;
			cnt++;
		}
		for (auto& i : v)
		{
			if (a <= 0)
			{
				break;
			}
			int temp = i;
			if (temp == 15)
			{
				cnt++;
			}
			i -= min(i, a);
			a -= temp;
		}
		cout << cnt << "\n";
	}
	return 0;
}

