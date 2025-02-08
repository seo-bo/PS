#include <bits/stdc++.h>
#include <unordered_map>
#define INF 2000000000
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, blue = 0;
	ll result = 0, higher = 0;
	cin >> num >> blue;
	vector<ll>ary(num, 0);
	for (int i = 0; i < num; ++i)
	{
		cin >> ary[i];
		higher += ary[i];
		result = max(result, ary[i]);
	}
	while (result <= higher)
	{
		ll mid = (result + higher) / 2, temp = 0, cnt = 0;
		for (int i = 0; i < num; ++i)
		{
			if (temp + ary[i] > mid)
			{
				temp = 0;
				cnt++;
			}
			temp += ary[i];
		}
		if (temp)
		{
			cnt++;
		}
		if (cnt <= blue)
		{
			higher = mid - 1;
		}
		else
		{
			result = mid + 1;
		}
	}
	cout << result;
	return 0;
}