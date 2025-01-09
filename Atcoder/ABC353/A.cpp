#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	int ff = 0;
	cin >> ff;
	int result = -1;
	for (int i = 1; i < num; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (ff < temp)
		{
			result = i + 1;
			break;
		}
	}
	cout << result;
	return 0;
}
