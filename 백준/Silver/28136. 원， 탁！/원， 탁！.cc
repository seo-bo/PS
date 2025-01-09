#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<int>v(N, 0);
	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	for (int i = 0; i < N; ++i)
	{
		if (i == N - 1)
		{
			if (v[i] >= v[0])
			{
				result++;
			}
		}
		else if (v[i] >= v[i + 1])
		{
			result++;
		}
	}
	cout << result;
	return 0;
}
