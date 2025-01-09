#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, K = 0, result = 0;
	cin >> N >> K;
	vector<int>ary(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> ary[i];
	}
	int i = 0;
	while (i < N)
	{
		int temp = K;
		temp -= ary[i];
		i++;
		if (i >= N)
		{
			result++;
			break;
		}
		while (temp >= ary[i] && i < N)
		{
			temp -= ary[i];
			i++;
			if (i >= N)
			{
				break;
			}
		}
		result++;
		if (i >= N)
		{
			break;
		}
	}
	cout << result;
	return 0;
}
