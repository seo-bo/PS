#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll S = 0, result = 0;
	cin >> S;
	while (S > 0)
	{
		result++;
		S -= result;
	}
	if (S < 0) // 5 -> -1 겹친걸 하나하나 분해 못하니까 2개를 1개로 퉁치자
	{
		result--;
	}
	cout << result;
	return 0;
}