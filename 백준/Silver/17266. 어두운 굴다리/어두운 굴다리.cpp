#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int end = 0, num = 0;
	cin >> end >> num;
	vector<int>v(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i];
	}
	int low = 0, high = end;
	while (low <= high)
	{
		bool change = false;
		int mid = (low + high) / 2;
		int pre = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] - mid > pre)
			{
				change = true;
				break;
			}
			else
			{
				pre = v[i] + mid;
			}
		}
		if (pre < end)
		{
			change = true;
		}
		if (change)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << low;
	return 0;
}