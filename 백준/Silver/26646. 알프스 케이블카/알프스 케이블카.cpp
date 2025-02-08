#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	vector<int> ary(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> ary[i];
	}
	int result = pow(abs((ary[0] - ary[1])), 2) + pow(abs((ary[0] + ary[1])), 2);
	int get = ary[0] + ary[1];
	for (int i = 1; i < num - 1; ++i)
	{
		get += ary[i + 1];
		result = min(result + pow(abs((ary[i] - ary[i + 1])), 2) + pow(abs((ary[i] + ary[i + 1])), 2), pow(abs(ary[0] - ary[i + 1]), 2) + pow(get * 2 - ary[0] - ary[i + 1], 2));
	}
	cout << result;
	return 0;
}
