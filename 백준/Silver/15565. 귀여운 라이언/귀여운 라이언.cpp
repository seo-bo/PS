#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, K = 0;
	cin >> N >> K;
	int R = 0, A = 0;
	vector<int>v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		if (v[i] == 1)
		{
			R++;
		}
		else
		{
			A++;
		}
	}
	int left = 0, right = 0, cnt = 0, result = INT_MAX;
	while (right < N)
	{
		if (v[right] == 1)
		{
			cnt++;
		}
		right++;
		while (cnt >= K)
		{
			result = min(result, right - left);
			if (v[left] == 1)
			{
				cnt--;
			}
			left++;
		}
	}
	if (result == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
	return 0;
}
