#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N = 0;
	cin >> N;
	ll result = 0;
	while (N > 0)
	{
		if (!(N % 5))
		{
			result += N / 5;
			break;
		}
		else
		{
			N -= 3;
			result++;
		}
	}
	if (N < 0)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
	return 0;
}
