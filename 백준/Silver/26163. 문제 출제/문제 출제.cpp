#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>cost(5);
	for (auto& i : cost)
	{
		cin >> i;
	}
	int ans = 0;
	for (int a = 0; a <= 15; ++a)
	{
		for (int b = 0; b <= 15; ++b)
		{
			for (int c = 0; c <= 15; ++c)
			{
				for (int d = 0; d <= 15; ++d)
				{
					for (int e = 0; e <= 15; ++e)
					{
						if (a + b + c + d + e <= 3)
						{
							int pivot = a + b * 2 + c * 3 + d * 4 + e * 5;
							if (pivot > 10)
							{
								continue;
							}
							ans = max(ans, a * cost[0] + b * cost[1] + c * cost[2] + d * cost[3] + e * cost[4]);
						}
						else
						{
							int pivot = a + b * 2 + c * 3 + d * 4 + e * 5;
							if (pivot > 15)
							{
								continue;
							}
							ans = max(ans, a * cost[0] + b * cost[1] + c * cost[2] + d * cost[3] + e * cost[4]);
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}